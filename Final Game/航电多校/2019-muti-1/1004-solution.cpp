// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while (cin >> n) {
		vector<double> l(n+1);
		vector<double> s(n+1);
		vector<double> v(n+1);
		for (int i=0; i<=n; i++){
			int tp ; cin >> tp;
			l[i] = tp;
		}
		for (int i=0; i<=n; i++){
			int tp; cin >> tp;
			s[i] = tp;
			// cin >> s[i];
		}
		for (int i=0; i<=n; i++){
			int tp; cin >> tp;
			v[i] = tp;
			// cin >> v[i];
		}

		double mx = 0;
		double len = 0;
		for (int i=0; i<=n; i++){
			double sum = s[i]/v[i];
			if (i != 0) len += l[i];
			mx = max(sum+len/v[i],mx);
		}
		cout << fixed << setprecision(12);
		cout << mx << endl;
	}
	return 0;
}
