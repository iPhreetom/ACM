#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;
vector<int> mp[maxn];
vector<int> ans;
int matrix[maxn][maxn];
bool vis[maxn];
int deep[maxn];

void push(int u, int v) {
	matrix[u][v] = 1;
	matrix[v][u] = 1;
	mp[u].push_back(v);
	mp[v].push_back(u);
}

void dfs(int root) {
	stack<int> st;
	memset(vis,0,sizeof(vis));
	ans.clear();

	st.push(root);
	vis[root] = 1;

	while (!st.empty()) {
		int p = st.top();
		st.pop();
		ans.push_back(p);
		for (int i=0; i<mp[p].size(); i++) {
		    int v = mp[p][i];
			if (!vis[v]) {
				vis[v] = 1;
				st.push(v);
			}
		}
	}

	for (int i=0; i<ans.size(); i++) {
	    cout << ans[i] << ' ';
	}
	cout << endl;
}

void bfs(int root) {
	queue<int> que;
	memset(vis,0,sizeof(vis));
	memset(deep,0,sizeof(deep));
	ans.clear();

	que.push(root);
	vis[root] = 1;
	deep[root] = 1;

	while(!que.empty()) {
		int p = que.front();
		que.pop();
		ans.push_back(p);
		for (int i=0; i<mp[p].size(); i++) {
			int v = mp[p][i];
			if (!vis[v]) {
				que.push(v);
				deep[v] = deep[p] + 1;
				vis[v] = 1;
			}
		}
	}

	for (int i=0; i<ans.size(); i++) {
	    cout << ans[i] << ' ';
	}
	cout << endl;
}

int main () {
	int m;
	cout << "input the number of edge : " << endl;
	cin >> m;
	cout << "Input two point of the edge: " << endl;
	for (int i=1; i<=m; i++) {
		int u,v;
		cin >> u >> v;
		push(u,v);
	}
	cout << "dfs(1) will get: ";
	dfs(1);
	cout << endl;
	cout << "bfs(1) will get: ";
	bfs(1);
	return 0;
}
