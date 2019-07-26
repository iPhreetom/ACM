// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	while(cin >> s) {
		vector<int> cnt(26,0);
		vector<int> l(26,0);
		vector<int> r(26,0);
		vector<queue<int>> place(26);
		vector<vector<int>> suf(s.size()+1,vector<int>(26,0));
		vector<int> now(26);
		string ans;
		int k;

		cin >> k;
		for (int i=0; i<26; i++){
			cin >> l[i] >> r[i];
		}
		for (int i=0; i<s.size(); i++){
			cnt[s[i]-'a']++;
		}

		// init
		for (int i=0; i<s.size(); i++){
			place[s[i]-'a'].push(i);
		}
		for (int i=s.size()-1; i>=0; i--) {
			for (int j=0; j<26; j++){
				suf[i][j] = suf[i+1][j];
			}
			suf[i][s[i]-'a']++;
		}

		int mx = 0;
		while(ans.size() < k) {
			bool change = false;
			for (int i=0; i<26; i++){
				while (!place[i].empty() && ans.size() < k && now[i] < r[i]) {
					int index = place[i].front();
					if (index < mx) {
						place[i].pop();
						continue;
					}
					bool can = true;
					int sum = 0;
					int mn = 0;

					for (int j=0; j<26; j++) {

						if (suf[index][j] < l[j]-now[j]) can = false;

						sum += min(r[j]-now[j],suf[index][j]);

						mn += max(l[j]-now[j],0LL);
						if (i==j && l[j]-now[j]>0) mn--;
					}
					// cout<<"index = "<<index<<endl;
					// cout<<"i = "<<i<<endl;
					// cout<<"mn = "<<mn<<endl;
					// cout<<"sum = "<<sum<<endl;
					// cout<<"ans = "<<ans<<endl;
					// cout << endl;


					if (ans.size()+sum < k) can = false;
					if (ans.size()+mn >= k) can = false;
					if (can) {
						change = true;
						ans.push_back('a'+i);
						now[i]++;
						mx = index;
						place[i].pop();
						break;
					}
					else break;
				}
				if (change) break;
			}
			if (!change) {
				break;
			}
		}
		if (ans.size() == k) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}
// zb 2
// 1 10
// 1 10
// 0 10
// 0 10
// 0 10
// 0 10
//
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
//
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
//
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
// 0 10
//
// 0 10
// 1 10

// 找到一个可用的字母后，应该再从a开始找
