// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool mp[3123][3123];
int pre[3123][3123];
int h[2123];
bool vis[3123][3123];
string lis[3123];


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> lis[i];
		for (int j=0; j<lis[i].size(); j++){
			mp[i][j+1] = lis[i][j]-'0';
		}
		for (int j=1; j<=m; j++){
			pre[i][j] = mp[i][j] + pre[i][j-1];
		}
	}

	int ans = 0;
	for (int i=1; i<=n; i++) {
		stack<pair<int,int>> st;
		for (int j=1; j<=m; j++){
			if (mp[i][j]) h[j] = h[j]+1;
			else h[j] = 0;
		}
		for (int j=1; j<=m; j++){
			bool flag = 0;
			while(!st.empty() && st.top().first > h[j]) {
				if (!flag) {
					if ( st.top().second == 0) {
						ans++;
						flag = true;
					}
				}
				else {
					ans++;
				}
				st.pop();
			}

			if (st.empty() || h[j]>st.top().first) {
				if (n == i || mp[i+1][j]==0 || flag) st.emplace(h[j],0);
				else st.emplace(h[j],1);
			}
			else if (st.top().first == h[j]) {
				if (mp[i+1][j] == 0) st.top().second = 0;
			}
			if(st.top().first == 0 && st.top().second == 0)
				st.top().second = 1;
		}
		// out
		bool flag = false;
		while(!st.empty()) {
			if (st.top().first == 0) break;
			if (!flag) {
				if (st.top().second == 0) {
					ans++;
					flag = 1;
				}
			}
			else {
				ans++;
			}
			st.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
