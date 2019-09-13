// fyt
#include<bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	unordered_map<int,int> mp;
	for (int i=0; i<n; i++){
		mp[v[i]]++;
	}

	int mx = 2;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	map<pair<int,int>,int> dp;
	for (int i=0; i<v.size(); i++){
		for (int j=0; j<v.size(); j++){
			unordered_map<int,int> mp2;
			mp2[v[i]]++;
			mp2[v[j]]++;
			if (mp2[v[i]] > mp[v[i]]) continue;

			int s = v[i];
			int t = v[j];
			int sum = 2;

			while( mp.find(s+t)!=mp.end() ){
				// if ( dp.find(make_pair(s,t))!=dp.end() ) {
				// 	sum += dp[make_pair(s,t)]-2;
				// 	break;
				// }

				if(mp[s+t]>mp2[s+t]){
					sum++;
					mp2[s+t]++;
					int temp = s+t;
					s = t;
					t = temp;
				}
				else break;
			}

			// dp[make_pair(v[i],v[j])] = max(sum,dp[make_pair(v[i],v[j])]);
			mx = max(sum,mx);
			if (mx == n) {
				cout << n << endl;
				return 0;
			}
		}
	}
	cout << mx << endl;
	return 0;
}
