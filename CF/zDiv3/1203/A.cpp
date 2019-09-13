// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i=0; i<n; i++){
		    cin >> v[i];
		}
		vector<int> lis;
		for (int i=0; i<v.size(); i++){
			lis.push_back(v[i]);
		}
		for (int i=0; i<v.size(); i++){
			lis.push_back(v[i]);
		}
		for (int i=0; i<v.size(); i++){
			lis.push_back(v[i]);
		}
		bool can = 0;
		for (int i=0; i<n*2; i++){
			int cnt = 0;
			bool f = 1;
			for (int j=0; j<n; j++){
				if (lis[i+j] != ++cnt) {
					f = 0;
					break;
				}
			}
			if (f) can = f;

			cnt = n;
			f = 1;
			for (int j=0; j<n; j++){
				if (lis[i+j] != cnt--) {
					f = 0;
					break;
				}
			}
			if (f) can = f;
		}
		if (can) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
