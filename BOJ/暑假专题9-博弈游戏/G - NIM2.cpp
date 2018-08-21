#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

set<int> ans;
void pre(int i){
	ans.insert(i);
	if(i < 2e18 && i > 0){
		pre(i*2 + 1);
	}
}

int f[10000000];

int psg(int t){
	int num = 0;
	for (int i=(t+1)/2; i<t; i++){
		if(num == f[i]){
			num++;
			i=(t+1)/2 -1;
		}
	}
	f[t]=num;
	return num;
}

int sg(int t){
	if(t%2==0){
		return t/2;
	}
	else{
		return sg(t/2);
	}
}

void solve(){
	int n,num=0;
	cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
	    cin>>a[i];
		num ^= sg(a[i]);
	}

	if(num){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// pre(1);
	// int t;cin>>t;
	// while(t--)solve();
	for (int i=1; i<=30; i++){
	    // cout<<sg(i)<<endl;
		cout<<"psg(i) = "<<psg(i)<<endl;
		cout<<"sg(i) = "<<sg(i)<<endl;
		// if(i%2 == 0){
		// 	cout<<f[i]<<endl;
		// }
		// else{
		// 	cout<<"f[i] = "<<f[i]<<endl;
		// 	cout<<"f[i/2] = "<<f[i/2]<<endl;
		// }
	}
	return 0;
}
