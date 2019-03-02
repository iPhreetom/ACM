#include<bits/stdc++.h>
using namespace std;

int dp[212345][212];

struct node {
	int s,t,d,w;
	node(){}
	node(int s,int t,int d,int w):s(s),t(t),d(d),w(w){}
	bool operator< (const node &r) const{
		if(this.s == r.s){
			return this.
		}
		return this->s < r.s;
	}
};

// 先算不影响的答案？
// 或者直接DP，然后出答案
// 但是怎么DP呢，他是贪心的取的，所以我们直接用DP（记忆化）
// 	记录，取了某一个以后，他会怎么取（如果不影响）

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;

	vector<node> v;
	node tp;
	for (int i=1; i<=k; i++){
		// int s,t,d,w;
		cin >> tp.s >> tp.t >> tp.d >> tp.w;
		v.push_back(tp);
	}
	sort(v.begin(),v.end());

	for (int i=1; i<=n; i++){
		for (int j=0; j<=m; j++){

		}
	}

	// 首先前i分钟，使用了j次阻碍
	// dp[i][j] = dp[i-1][j+1],dp[i-1][j]+
	return 0;
}
