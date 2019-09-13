// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int vis[212345];
int ans[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}

	queue<int> que1,que2;
	que1.push(1);
	int cnt = 0;
	memset(vis,0x3f,sizeof(vis));
	while(!que1.empty() || !que2.empty()){
		if (!que1.empty()) {
			while(!que1.empty()) {
				int u = que1.front();
				que1.pop();
				if(u == 0)continue;
				if (vis[u]<=cnt) continue;
				vis[u] = 1;
				ans[u] = cnt;
				que2.push(u+1);
				que2.push(a[u]);
				que2.push(u-1);
			}
			cnt++;
		}
		else {
			while(!que2.empty()){
				int u = que2.front();
				que2.pop();
				if(u == 0)continue;
				if (vis[u]<=cnt) continue;
				vis[u] = 1;
				ans[u] = cnt;
				que1.push(u+1);
				que1.push(a[u]);
				que1.push(u-1);
			}
			cnt++;
		}
	}

	for (int i=1; i<=n; i++){
		cout << ans[i] << " \n"[i==n?1:0];
	}
	return 0;
}
