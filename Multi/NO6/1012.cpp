// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		double x,y;
		double a,b;
		cin>>a>>b>>x>>y;
		x = -x;
		// ab is the slope
		// xy is the point

		double ta = b/a;
		double k = ta;
		double co = a/sqrt(a*a+b*b);
		double si = b/sqrt(a*a+b*b);

		double h = (y-k*x)*co;
		double g = 9.8;
		double gx = g*si;
		double gy = g*co;

		double x0 = (y*k+x)/(k*k+1);
		double y0 = (y*k*k+x*k)/(k*k+1);
		double d = sqrt(x0*x0+y0*y0);
		// cout<<"x0 = "<<x0<<endl;
		// cout<<"y0 = "<<y0<<endl;
		// cout<<"d = "<<d<<endl;

		double t = sqrt(2*h/gy);
		// t *= 2;

		int ans = 0;
		double dis=0;
		double vx=0;
		for(int i=0;i<=50;i++){
			dis += vx*t+0.5*gx*t*t;
			vx += gx*t;

			if(dis >= d)break;
			ans++;

			dis += vx*t+0.5*gx*t*t;
			vx += gx*t;
		}
		cout<<ans<<endl;


	}
	return 0;
}
