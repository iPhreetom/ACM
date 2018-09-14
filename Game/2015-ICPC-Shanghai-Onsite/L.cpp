// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int gcd(int m, int n){
    int k;
    while(m!=n){
		cout<<"m = "<<m<<' ';
		cout<<"n = "<<n<<endl;
        if(m>n){
            k=m-n;
            m=n;
            n=k;
        }
        else{
            k=n-m;
            m=n;
            n=k;
        }
    }
    return m;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;cin>>tt;
	for(int nn=1;nn<=tt;nn++){
		int x,y;
		cin>>x>>y;
		cout<<gcd(x,y)<<endl;
	}
	return 0;
}
