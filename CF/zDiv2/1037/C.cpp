// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	int ans = 0;
	string b;
	string a;
	cin>>n;
	cin>>a>>b;

	if(a.size() == 1){
		if(a == b)cout<<0<<endl;
		else cout<<1<<endl;
	}
	else{
		for (int i=0; i<a.size()-1; i++){
			if(a[i]!=b[i] && a[i+1]!=b[i+1] && a[i] + a[i+1] == b[i] + b[i+1]){
				swap(a[i],a[i+1]);
				ans++;
			}
		}
		for (int i=0; i<a.size(); i++){
		    if(a[i] != b[i]){
				ans++;
				a[i] = b[i];
			}
		}
		cout<<ans<<endl;
	}
	// cout<<a<<endl;
	// cout<<b<<endl;
	return 0;
}
