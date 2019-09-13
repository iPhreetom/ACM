// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

double get(double n) {
	double f[55];
	for (int i=0; i<55; i++){
	    f[i] = 0 ;
	}
	if (n == 1) return 1.0;

	double ret = 0;
	f[1] += 1.0/n;
	ret += f[1];

	for (int i=n-1; i>=2; i--) {
		f[i] += (1.0/n) * (1.0/(n-i+1));
		for (int j=i+1; j<=n-1; j++) {
			f[i] += 1.0/n*(1.0/(n-i+1))*f[j];
		}
		ret += f[i];
	}

	return ret;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int cs=1; cs<=T; cs++) {
		double ans1 = 0,ans2 = 0;
		int n,m;
		cin >> n >> m;
		ans1 = get(n);
		for (int i=1; i<=m; i++){
			ans2 += 1.0/m*get(i);
		}
		cout << fixed << setprecision(6) << "Case #" << cs << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}
