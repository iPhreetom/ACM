// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	int lis[1000];
	for (int i=1; i<=n; i++){
	    cin>>lis[i];
	}
	int l = 1;
	int r = n;
	int ans = -1;
	// if(n == 1){
	// 	if(lis[0] == 2){
	// 		ans = min(a,b);
	// 	}
	// 	else ans = 0;
	// }
	// else{
	ans = 0;
	while(l <= r){
		if(l == r){
			if(lis[l] == 2){
				ans +=min(a,b);
			}
		}
		else if(lis[l] == 2 || lis[r] == 2){
			if(lis[l] == 2 && lis[r] == 2){
				ans += min(a,b)*2;
			}
			else if(lis[l] == 1)ans += b;
			else if(lis[l] == 0)ans += a;
			else if(lis[r] == 1)ans += b;
			else if(lis[r] == 0)ans += a;
		}
		else{
			if(lis[l] != lis[r])ans = -1;
		}
		if(ans == -1)break;
		l ++;
		r --;
	}
	// }
	cout<<ans<<endl;
	return 0;
}
