#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int k;
int a[21234];
int ans[21234];
int dp[2005][2005];


int findit(int res,int index,int mx){
	if(index > n){
		return -12345;
	}

	mx = max(a[index],mx);

	if(res == 1){
		int t = 0;
		for(int i=index;i<=n;i++){
			t = max(t,a[i]);
		}
		t = max(t,mx);
		return dp[res][index] = t;
	}
	if(dp[res][index]){
		return dp[res][index];
	}
	else{
		int t1 = mx+findit(res-1,index+1,0);
		int t2 = findit(res,index+1,a[index]);
		if(t1 > t2){
			dp[res][index] = t1;
			ans[index] = index;
		}
		else{
			dp[res][index] = t2;
		}
	}
	return dp[res][index];
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	cout<<findit(k,1,0)<<endl;
	for(int i=0;i<=n;i++){
		if(ans[i]){
			cout<<ans[i]<<' ';
		}
	}
	cout<<endl;
	return 0;
}
