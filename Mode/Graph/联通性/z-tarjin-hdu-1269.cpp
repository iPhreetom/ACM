#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 1e5+5;

vector<int> mp[maxn];
bool instack[maxn];
stack<int> s;
int dfn[maxn];
int low[maxn];
int belong[maxn];//Belong[i] = a; 表示i这个点属于第a个连通分量
int bcnt,dindex;//bcnt用来记录连通分量的个数，dindex表示到达某个点的时间

void init(int n) {
	for (int i=0; i<=n; i++){
		mp[i].clear();
		belong[i] = 0;
		dfn[i] = 0;
		low[i] = 0;
	}
	bcnt = 0;
	dindex = 0;
	while(!s.empty())s.pop();
}

void tarjin(int u) {
	dfn[u] = low[u] = ++dindex;
	s.push(u);
	instack[u] = true;
	for (int i=0; i<mp[u].size(); i++){
		int &v = mp[u][i];
		if(!dfn[v]) {
			tarjin(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v]){
			low[u] = min(low[u],low[v]);
		}
	}
	if(dfn[u] == low[u]) { // u就是根节点，并且找到了所有的联通分量
		bcnt ++;
		int v;
		do {
			v = s.top();
			s.pop();
			instack[v] = false;
			belong[v] = bcnt;
		} while(u != v);
	}
}

void all_tarjin(int n) {
	for (int i=1; i<=n; i++){
		if(!dfn[i]) tarjin(i);
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	while(1) {
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		init(n);
		for (int i=1; i<=m; i++){
			int u, v;
			cin >> u >> v;
			mp[u].push_back(v);
		}
		all_tarjin(n);
		if(bcnt == 1) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
