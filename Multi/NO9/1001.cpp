#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n,m,t;
int f(int x){
	int ans = 1;
	for (int i=1; i<=x; i++){
	    ans *= i;
		ans %= t;
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>t;
		if(n == 1){
			cout<<f(m)<<endl;
		}else if(m == 1){
			cout<<f(n)<<endl;
		}else{
			int ans = 1;
			int num = (m-1)*(n-1);
			int tp = n*m;
			for (int i=0; i<num; i++){
				ans *= (tp-i);
				ans %= t;
			}
			ans *= f(n);
			ans %= t;
			ans *= f(m);
			ans %= t;
			cout<<ans<<endl;
		}
	}
	return 0;
}
