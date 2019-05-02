// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	while(cin >> n >> m >> k) {
		vector<string> v(n+1);
		for (int i=1; i<=n; i++){
			cin >> v[i];
		}
		vector<string> ans(n*k+1);
		for (int i=1; i<=n; i++){
			for (int q=1; q<=k; q++) {
				for (int j=0; j<v[i].size(); j++){
					for (int p=1; p<=k; p++) {
						cout << v[i][j];
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
