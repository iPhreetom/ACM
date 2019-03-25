// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,e,p;
	cin >> a >> b >> e >> p;

	vector<vector<int>> mp(e+2);
	vector<vector<int>> mp2(e+2);

	vector<int> ans1(e+2, 0);
	vector<int> ans2(e+2, 0);

	for (int i=1; i<=p; i++){
		int x,y;
		cin >> x >> y;
		x++;
		y++;
		mp[x].push_back(y);
		mp2[y].push_back(x);
	}

	for (int q=1; q<=e; q++){
		queue<int> que;
		vector<bool> vis(e+2, 0);

		int cnt = 0;
		que.push(q);

		while(!que.empty()){
			int u = que.front();
			vis[u] = 1;
			cnt++;
			que.pop();
			for (int i=0; i<mp2[u].size(); i++){
				int v = mp2[u][i];
				if (!vis[v]) {
					que.push(v);
					vis[v] = 1;
				}
			}
		}
		ans2[q] = cnt;
	}
	// ans2[i] 表示i这个点，往上走的大小
	// ans2[i] 是 取i需要至少取i个，才有可能
	// 取了 ans2[i] 个，它一定有可能被取到

	for (int q=1; q<=e; q++){
		queue<int> que;
		vector<bool> vis(e+2, 0);
		int cnt = 0;
		que.push(q);
		while(!que.empty()){
			int u = que.front();
			vis[u] = 1;
			que.pop();
			cnt++;
			for (int i=0; i<mp[u].size(); i++){
				int v = mp[u][i];
				if (!vis[v]) {
					que.push(v);
					vis[v] = 1;
				}
			}
		}
		ans1[q] = cnt;
	}
	// ans1[i] 表示 如果不取i，最多能取e-ans1[i]个
	// 取ans1[i]+1个就能够取到i

	int sum = 0;
	for (int i=1; i<=e; i++){
	    if(e-ans1[i]+1 <= a)sum++;
	}
	cout << sum << endl;


	sum = 0;
	for (int i=1; i<=e; i++){
		if(e-ans1[i]+1 <= b)sum++;
	}
	cout << sum << endl;


	sum = 0;
	for (int i=1; i<=e; i++){
		if(ans2[i] <= b)sum++;
	}
	cout << e-sum << endl;

	return 0;
}
