#include<bits/stdc++.h>
using namespace std;

int dp[200005][2];
int a[200005];
int n;

int dpo(int index,bool choose){
	//int n = a[index];

	if(index == n){
		return 0;
	}

	if(choose == 1){
		if(dp[index][choose] != 0)return dp[index][choose];
		for(int i=index;i<n;i++){
			if(a[i] == a[index]+1){
				dp[index][choose] = dpo(i,choose)+1;
			}
		}
		return dp[index][choose];
	}
	else{
		if(dp[index][choose] != 0)return dp[index][choose];
		else{
			dp[index][choose] = max(dpo(index+1,0),dpo(index,1));
		}
		return dp[index][choose];
	}
}

void solve(){
	cout<<dpo(0,0)<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve();
	return 0;
}
