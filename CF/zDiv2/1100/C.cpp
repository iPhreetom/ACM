// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

double n, midr;
double l = 0, r = midr * 7;
int cnt = 1e5;
double degree;
double pi;

inline bool check(double &R){
	double comp = R/(midr+R);
	comp = asin(comp)*180/pi;
	// cout<<"comp = "<<comp<<endl;
	if(comp <= degree) {
		return 1;
	}
	else return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	pi = asin(1)*2;

	// cout<<sin(30.0/180.0*pi)<<endl;
	// cout<<asin(0.5)*180/pi<<endl;
	// cout<<"pi = "<<pi<<endl;

	cin >> n >> midr;
	degree = 180.0/n;
	r = midr*70;

	while(cnt--) {
		double mid = l + (r-l)/2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(12) << l << endl;
	return 0;
}
