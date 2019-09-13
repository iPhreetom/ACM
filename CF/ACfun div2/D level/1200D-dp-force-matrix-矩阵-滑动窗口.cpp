// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string mp[2123];
int dp[4123][4123];
int lt[4123],rt[4123];
int ans = 0;
int n, k;

void getrow() {
	for (int i=1; i<=n; i++){
		bool all = 1;
		for (int j=1; j<=n; j++){
			if (mp[i][j] == 'B') all = 0;
		}
		if (all) {lt[i] = -1; rt[i] = -1; ans++; continue;}
		for (int j=1; j<=n; j++) {
			if (mp[i][j] == 'B') {lt[i] = j; break;}
		}
		for (int j=n; j>=1 ;j--) {
			if (mp[i][j] == 'B') {rt[i] = j; break;}
		}
		int rangel=-1, ranger;
		for (int j=1; j<=lt[i]; j++){
			if (j+k-1 >= rt[i]) {rangel=j; break;}
		}
		if (rangel == -1) lt[i]=rt[i]=-2;
		rt[i] = lt[i];
		lt[i] = rangel;
	}

	for (int j=1; j<=n; j++) {
		int now = 0;
		for (int i=1; i<=k; i++) {
			if (lt[i]<=j && rt[i]>=j) now++;
		}
		dp[1][j] += now;
		for (int i=2; i<=n; i++) {
			if (lt[i-1]<=j && rt[i-1]>=j) now--;
			if (lt[i+k-1]<=j && rt[i+k-1]>=j) now++;
			dp[i][j] += now;
		}
	}
}

void getcolumn() {
	memset(lt,0,sizeof(lt));
	memset(rt,0,sizeof(rt));
	for (int i=1; i<=n; i++){
		bool all = 1;
		for (int j=1; j<=n; j++){
			if (mp[i][j] == 'B') all = 0;
		}
		if (all) {lt[i] = -1; rt[i] = -1; ans++; continue;}
		for (int j=1; j<=n; j++) {
			if (mp[i][j] == 'B') {lt[i] = j; break;}
		}
		for (int j=n; j>=1 ;j--) {
			if (mp[i][j] == 'B') {rt[i] = j; break;}
		}
		int rangel=-1, ranger;
		for (int j=1; j<=lt[i]; j++){
			if (j+k-1 >= rt[i]) {rangel=j; break;}
		}
		if (rangel == -1) lt[i]=rt[i]=-2;
		rt[i] = lt[i];
		lt[i] = rangel;
	}

	for (int j=1; j<=n; j++) {
		int now = 0;
		for (int i=1; i<=k; i++) {
			if (lt[i]<=j && rt[i]>=j) now++;
		}
		dp[1][j] += now;
		for (int i=2; i<=n; i++) {
			if (lt[i-1]<=j && rt[i-1]>=j) now--;
			if (lt[i+k-1]<=j && rt[i+k-1]>=j) now++;
			dp[i][j] += now;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> mp[i];
		mp[i] = "#"+mp[i];
	}
	getrow();
	int cnt = 1;
	for (int i=1; i<=n; i++){
		for (int j=cnt; j<=n; j++){
			swap(mp[i][j],mp[j][i]);
			swap(dp[i][j],dp[j][i]);
		}
		cnt++;
	}
	getcolumn();
	int mx = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			mx = max(mx,dp[i][j]);
		}
	}
	cout << mx+ans << endl;
	return 0;
}
