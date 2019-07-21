// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	int ans = 0;
	vector<int> v;
	s.push_back('-');
	for (int i=1; i<s.size(); i++){
		if (s[i] == s[i-1]) {
			cnt++;
		}
		else {
			if (s[i] == 'o') {
				if (cnt != 0) v.push_back(cnt);
				cnt = 1;
			}
			else {
				if (!v.empty() && (s[i] == 'v' && s[i+1] != 'v')) {
					i++;
					cnt++;
				}
				else {
					if (cnt != 0) v.push_back(cnt);
					cnt = 0;
				}
			}
		}
	}

	if (v.size() < 3) {
		cout << 0 << endl;
		return 0;
	}


	ans = 0;
	vector<int> pre(v.size());
	pre[0] = v[0];
	for (int i=2; i<v.size(); i+=2){
		pre[i] = pre[i-2]+v[i];
	}

	int len = v.size();
	int ed = 0;
	if (len % 2 == 0) ed = len-2;
	else ed = len-1;

	for (int i=0; i<len-2; i+=2){
		ans += pre[i]*v[i+1]*(pre[ed]-pre[i]);
	}


	cout << ans << endl;
	return 0;
}
