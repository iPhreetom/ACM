// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int dp[32][2][2][2][2];
int A,B,C;
int dfs(int pos, bool freea, bool freeb, bool lessand, bool greaterxor) {
	if (pos < 0) return 1;
	int &val = dp[pos][freea][freeb][lessand][greaterxor];
	if (val != -1) return val;

	int newa=1;
	int newb=1;
	int newand=1; // shoule less than it
	int newxor=0; // should greater than it
	if (!freea) newa = (A>>pos)&1;
	if (!freeb) newb = (B>>pos)&1;
	if (!lessand) newand = (C>>pos)&1;
	if (!greaterxor) newxor = (C>>pos)&1;

	val = 0;
	for (int i=0; i<=newa; i++){
	    for (int j=0; j<=newb; j++){
			if (!lessand && (i&j) > newand) continue;
			if (!greaterxor && (i^j) < newxor) continue;
			val += dfs(pos-1, freea||(newa&&i!=newa), freeb||(newb&&j!=newb), lessand||((i&j)<newand), greaterxor||(i^j)>newxor);
	    }
	}
	return val;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> A >> B >> C;
		memset(dp,-1,sizeof(dp));
		int ans = dfs(31,0,0,0,0);
		if (A>=C) ans -= (A-C+1);
		if (B>=C) ans -= (B-C+1);
		cout << A*B-ans << endl;
	}
	return 0;
}
