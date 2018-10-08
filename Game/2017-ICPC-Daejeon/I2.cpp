// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> f;
vector<int> a;
vector<int> b;

void getFail(auto &p){
	f.clear();
	f.resize(p.size()+1);
	f[0] = 0;
	f[1] = 0;
	for (int i=1; i<p.size(); i++){
	    int j = f[i];
		while(j && p[i]!=p[j])j = f[j];
		f[i+1] = p[i] == p[j]? j+1 : 0;
	}
}

int n;
bool check(int mid){
	b.clear();
	b.resize(n-mid);
	for (int i=mid; i<a.size(); i++){
		b[i-mid] = a[i];
	}
	getFail(b);

	int len = b.size();
	int res = len - f[len];


	if(res != len)return 0;
	else return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	a.resize(n);
	for (int i=n-1; i>=0; i--){
		cin>>a[i];
	}
	getFail(a);
	int ansl = n-1;
	int ansr = 1;
	for (int i=1; i<f.size(); i++){
		if(ansl + ansr == i-f[i] + f.size()-i-1){
			if(i-f[i] != 0 && i-f[i] < ansr){
				ansl = f.size()-i-1;
				ansr = i-f[i];
			}
		}
		else if(ansl + ansr > i-f[i] + f.size()-i-1){
			ansl = f.size()-i-1;
			ansr = i-f[i];
		}
		// cout<<"i-f[i] = "<<i-f[i]<<endl;
		// cout<<"f.size()-i-1 = "<<f.size()-i-1<<endl;
	}

	cout<<ansl<<' '<<ansr<<endl;

	return 0;
}
