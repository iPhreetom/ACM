// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

double d;

int check(double &mid){
	// cout<<"(d/mid + mid) = "<<(d/mid + mid)<<endl;
	if((d/mid + mid) < d)return 2;
	if((d/mid + mid) > d)return 1;
	return 3;
}

signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int dd;
		cin>>dd;
		d = dd;
		if(d == 0){
			cout<<0<<' '<<0<<endl;
			return 0;
		}

		if(sqrt(d)+sqrt(d) > d){
			cout<<"N"<<endl;
		}
		else if(sqrt(d)+sqrt(d) == d){
			cout<<fixed<<setprecision(9)<<sqrt(d)<<' '<<sqrt(d)<<endl;
		}
		else{
			// erfen
			double l = 1e-7;
			double r = sqrt(d);
			int count = 0;
			while(l < r){
				count++;
				if(count == 1e4)break;
				double mid = l+(r-l)/2;
				int now = check(mid);

				// cout<<"now = "<<now<<endl;
				// cout<<"l = "<<l<<endl;
				// cout<<"r = "<<r<<endl;


				if(now == 1)l = mid;
				else if(now == 2)r = mid;
				else break;
			}
			cout<<fixed<<setprecision(9)<<l<<' '<<d/l<<endl;
		}
	}
	return 0;
}
