// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int cnt[11];
int n;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	vector<int> v(n+1);
	for (int i=1; i<=n; i++){
		cin >> v[i];
	}

	int ans = 1;
	for (int i=1; i<=n; i++){
		cnt[v[i]]++;

		map<int,int> mp;
		for (int i=1; i<=10; i++){
			if(cnt[i])mp[cnt[i]]++;
		}
		if(mp.size() == 2) {
			auto ite = mp.begin();
			auto ite2 = mp.begin();
			ite2++;
			if ((ite2->first - ite->first == 1 && ite2->second == 1) || (ite->first == 1 && ite->second == 1)) {
				ans = i;
			}
		}
		else if(mp.size() == 1){
			auto ite = mp.begin();
			if ((ite->first == 1)) {
				ans = i;
			}
			else if(ite->second == 1) {
				ans = i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
