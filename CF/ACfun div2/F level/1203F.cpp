// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[112];
int dp[112];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(dp,0x3f,sizeof(dp));
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> up;
	vector<pair<int,int>> down;
	for (int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		if (b < 0) down.emplace_back(a+b,-b);
		else up.emplace_back(a,b);
	}
	sort(up.begin(),up.end());
	sort(down.begin(),down.end());

	int ans = 0;
	for (int i=0; i<up.size(); i++){
		if (x >= up[i].first) {ans++; x+=up[i].second;}
	}

	for (int now=0; now<=30000; now++) {
		int temp = now;
		int cnt = 0;
		memset(vis,0,sizeof(vis));
		for (int i=0; i<down.size(); i++){
			if (!vis[i] && temp >= down[i].first) {
				cnt++;
				temp += down[i].second;
				dp[cnt] = min(dp[cnt],temp);
				vis[i] = 1;
				break;
			}
		}
	}
	int add = 0;
	for (int i=1; i<=n; i++){
		if (x >= dp[i]) {
			add = i;
		}
	}
	cout << add + ans << endl;
	return 0;
}
