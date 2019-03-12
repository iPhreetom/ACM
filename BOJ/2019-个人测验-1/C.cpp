#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

double lis[2123][2123];
double prefix[2123];

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;
	double p;
	cin >> n >> p >> t;
	double ans = 0;

	// for (int i=1; i<=min(n,t); i++) {
	// 	double tp = 0;
	// 	for (int j=i; j<=t; j++) {
	// 		tp += pow(p,i) * pow((1-p),(j-i));
	// 		// cout << "ans = " << ans << endl;
	// 	}
	// }

	for (int i=1; i<=t; i++) {
		for (int j=min(i, n); j>=1; j--) {
			if(j == 1) {
				// ans += pow((1-p), i-1) * p;
				lis[i][1] = pow((1-p), i-1) * p;
				prefix[1] += lis[i][1];
			}
			else {
				lis[i][j] = (prefix[j-1] * p);
				prefix[j] += lis[i][j];
			}
		}
	}

	for (int i=1; i<=n; i++) {
		cout << "prefix[i] = " << prefix[i] << endl;
	}

	for (int i=1; i<=t; i++) {
	    for (int j=1; j<=n; j++) {
			ans += lis[i][j];
	    }
	}


	// cout << "ans = " << ans << endl;
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
