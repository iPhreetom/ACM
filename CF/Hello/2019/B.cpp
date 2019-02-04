// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// bool dp[16][360];
int n;
vector<int> a;
bool findit = 0;

void dfs(int i,int v) {
	// if(dp[i][v])return ;
	int ap = (v+a[i]+360)%360;
	int bp = (v-a[i]+360)%360;
	if(i == n-1){
		if(ap == 0 || bp == 0){
			findit = 1;
		}
		return ;
	}
	dfs(i+1,ap);
	dfs(i+1,bp);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
		int t;cin>>t;
		a.push_back(t);
	}
	dfs(0,0);
	if(findit){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
