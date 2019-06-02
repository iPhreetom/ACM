#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


const int maxn = 212345;
vector<int> mp[maxn];
vector<int> degree(maxn);
vector<int> rk(maxn);

void getrk(int n) {
	queue<int> que;
	for (int i=1; i<=n; i++) {
		if (degree[i] == 0) {
			que.push(i);
			rk[i] = 1;
		}
	}
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i=0; i<mp[u].size(); i++) {
			int &v = mp[u][i];
		    degree[v]--;
			if (degree[v] == 0) {
				que.push(v);
				rk[v] = rk[u]+1;
			}
		}
	}
}

void getIdRank(int n) {
	priority_queue<int,vector<int>,greater<int>> que;
	int index = 0;
	for (int i=1; i<=n; i++) {
		if (degree[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int u = que.top();
		// rk[u] = ++index;
		if (index == 0) {
			cout << u;
		}
		else {
			cout << ' ' << u;
		}
		++index;
		que.pop();
		for (int i=0; i<mp[u].size(); i++) {
			int &v = mp[u][i];
		    degree[v]--;
			if (degree[v] == 0) {
				que.push(v);
				rk[v] = rk[u]+1;
			}
		}
	}
}

void solver1() {
	int n,m;
	while (cin >> n >> m) {
		for (int i=0; i<=n+510; i++) {
			mp[i].clear();
			degree[i] = 0;
			rk[i] = 0;
		}
		for (int i=1; i<=m; i++) {
			int win,lose;
			cin >> win >> lose;
			mp[win].push_back(lose);
			degree[lose]++;
		}
		getIdRank(n);
		// for (int i=1; i<=n; i++) {
		// 	if (i == 1) cout << rk[i];
		// 	else cout << ' ' << rk[i];
		// }
		cout << endl;
	}
}
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	solver1();
	return 0;
}
