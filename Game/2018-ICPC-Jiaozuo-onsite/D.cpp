#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	double pi = acos(0);
	cin >> t;
	while (t--) {
		double a,b,r,d;
		cin >> a >> b >> r >> d;
		double lt = r+a;
		double rt = b;
		double ans = sqrt(lt*lt + rt*rt);
		cout << fixed << setprecision(9) << ans-r << endl;
		double degree = 180*atan(rt/lt)/pi;
		cout << "degree = " << degree << endl;
	}
	return 0;
}
