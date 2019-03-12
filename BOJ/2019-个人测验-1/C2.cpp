#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

double lis[2123][2123];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;
	double p;
	cin >> n >> p >> t;

	// lis[1][1] = p;
	for (int i=0; i<=t; i++) {
		lis[i][0] = pow((1-p),i);
	}

	for (int i=1; i<=t; i++) {
		for (int j=1; j<=n; j++) {
			lis[i][j] = lis[i-1][j-1]*p + lis[i-1][j]*(j == n ? 1 : (1-p));
		}
	}
	double a = 0;
	double b = 0;
	for (int i=1; i<=n; i++) {
		// cout << "lis[t][i] = " << lis[t][i] << endl;
		a += lis[t][i] * i;
		b += lis[t][i];
	}
	// cout << "b = " << b << endl;


	cout << fixed << setprecision(9) << a << endl;
	return 0;
}
