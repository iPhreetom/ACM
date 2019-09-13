#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,m,k;
		cin >> n >> m >> k;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin >> v[i];
		}
		bool ok = 1;
		for (int i=0; i<(int)v.size()-1; i++){
			if (v[i]+m+k >= v[i+1]) {
				m += v[i]-v[i+1]+(min(v[i+1],k));
			}
			else {
				ok = 0;
				break;
			}
		}
		// cout<<"m = "<<m<<endl;
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
