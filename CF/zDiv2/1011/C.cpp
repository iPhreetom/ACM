#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<double> arra;
vector<double> arrb;
double eps = 1e-7;
int n,m;
int mx;


bool check(double f){
	double w = f+m;
	// cout<<"-----weight---:"<<w<<endl;
	for(int i=0;i<n-1;i++){
		// cout<<f<<endl;
		// cout<<w/arra[i]<<endl;
		f -= w/arra[i];
		if(f<0)return 0;
		w -= w/arra[i];

		// cout<<f<<endl;
		f -= w/arrb[i+1];
		if(f<0)return 0;
		w -= w/arrb[i+1];
	}

	f -= w/arra[n-1];
	if(f<0)return 0;
	w -= w/arra[n-1];

	f -= w/arrb[0];
	if(f<0)return 0;
	w -= w/arrb[0];

	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;

	for(int i=0;i<n;i++){
		double t;
		cin>>t;
		arra.push_back(t);
	}
	for(int i=0;i<n;i++){
		double t;
		cin>>t;
		arrb.push_back(t);
	}

	double l = 0;
	double r = 1e14;
	// cout<<r<<endl;
	// cout<<eps<<endl;
	// cout<<abs(r-l)<<endl;
	while(abs(r-l) > eps){
		double mid = l + (r-l)/2;
		if(check(mid))r = mid;
		else l = mid;
	}

	if(!check(1e14)){
		cout<<-1<<endl;
		// cout<<"--"<<endl;
		return 0;
	}

	if(check(l)){
		cout<<fixed<<setprecision(9)<<l<<endl;
	}else{
		cout<<fixed<<setprecision(9)<<r<<endl;
	}



	return 0;
}
