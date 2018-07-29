#include<bits/stdc++.h>
#define double long long
#define double long double
using namespace std;


vector<double> arr;
int n,m;

bool is_mid_too_small(double mid){
	int x = 0;
	for(auto i:arr){
		x += (int)(i/(mid));
	}
	if(x < m)return false;
	else return true;
}

void digui(double l,double r){
	// cout<<l<<' '<<r<<endl;
	if(abs(l-r) < 0.001){
		cout<<fixed<<setprecision(2)<<r<<endl;
		return ;
	}

	if(is_mid_too_small((l+r)/2)){
		digui((l+r)/2,r);
	}
	else{
		digui(l,(l+r)/2);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(double i=0;i<n;i++){
		double t;
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end());

	double l=0,r=20000;
	digui(l,r);

	// cout<<l<<' '<<r<<endl;
	// if(is_mid_too_small(r))cout<<fixed<<setprecision(2)<<r<<endl;
	// else cout<<fixed<<setprecision(2)<<l<<endl;

	return 0;
}
