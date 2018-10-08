// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	for(int ks=1;ks<=tt;ks++){
		int n;
		int ans=1;
		cin>>n;

		for (int i=1; i<=n; i++){
		    cin>>a[i];
			if(a[i] %3 != 0)ans = 0;
		}

		cout<<"Case #"<<ks<<": "<<(ans?"Yes":"No")<<endl;
	}
	return 0;
}
