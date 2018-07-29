#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][105];
ll n,b;
ll a[105];

int dpi(int ii,int re){
	if(ii == n)return 0;

	if(dp[ii][re] != 0){
		return dp[ii][re];
	}

	ll odd=0,even=0;
	for(int i=0;i<ii;i++){
		if(a[i]%2==1)odd++;
		else even++;
	}

	if(odd == even){
		if(re >= abs(a[ii]+1 - a[ii]) ){
			dp[ii][re] = max(dpi(ii+1,re),dpi(ii+1,re-abs(a[ii+1]-a[ii]))+1);
		}
		else{
			dp[ii][re] = dpi(ii+1,re);
		}
	}
	else{
		dp[ii][re] = dpi(ii+1,re);
	}
	return dp[ii][re];
}

ll even,odd;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==1)odd++;
		else even++;
	}
	dpi(0,b);
	if(odd==even)cout<<dp[0][b]-1<<endl;
	else cout<<dp[0][b]<<endl;
	return 0;
}
