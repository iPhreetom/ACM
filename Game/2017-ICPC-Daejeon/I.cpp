// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> f;
vector<int> a;

void getFail(auto &p,int mid){
	f.resize(p.size()+1);
	f[mid] = mid;
	f[mid+1] = mid;
	for (int i=mid+1; i<p.size(); i++){
	    int j = f[i];
		while(j!=mid && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : mid;
	}
}

int n;
bool check(int mid){
	getFail(a,mid);
	int len = n;
	int res = len - f[n];
	cout<<"f[n] = "<<f[n]<<endl;
	cout<<"res = "<<res<<endl;
	cout<<"mid = "<<mid<<endl;
	cout<<endl;
	if(res != len-mid+1)return 0;
	else return 1;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int l = 0;
	int r = n;

	while(l+1<r){
		int mid = l+(r-l)/2;
		if(check(mid))l = mid;
		else r = mid;
	}

	return 0;
}
