// fyt
#include<bits/stdc++.h>
using namespace std;


vector<int> mp[212345];
// 最近的有分叉的点O(N)往下走
// 记录每个点的深度（避免不必要的询问）
//
const int maxn = 212345;
vector<int> tree[maxn + 5]; // tree[i]表示节点i的相邻节点
int d[maxn + 5]; // d[i]表示以i为根的子树的节点个数
int fa[maxn + 5];
#define INF 10000000
int minNode = 1;
int minBalance;
int num = 0;
int laf = -1;

void dfs(int node, int parent) // node and its parent
{
    d[node] = 1; // the node itself
    int maxSubTree = 0; // subtree that has the most number of nodes
    for (int i = 0; i < tree[node].size(); i++) {
        int son = tree[node][i];
        if (son != parent) {
            dfs(son, node);
            d[node] += d[son];
            maxSubTree = max(maxSubTree, d[son]);
        }
    }
    maxSubTree = max(maxSubTree, N - d[node]); // "upside substree with (N - d[node]) nodes"
    if (maxSubTree < minBalance) {
        minBalance = maxSubTree;
        minNode = node;
    }
}

void getfa(int u, int fs) {
    for (int i=0; i<tree[u].size(); i++){
        int v = tree[u][i];
        if (v == fs) continue;
        fa[v] = u;
        getfa(v, u);
    }
}

int main() {
	int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    getfa(1, -1);
    while(num != 1) {
        minBalance = INF;
        minNode = 1;
        memset(d,0,sizeof(d));
        dfs(minNode,laf);
        laf = fa[minNode];
        cout << "d " << minNode << endl;
        int dis1; cin >> dis1;
        cout << "d " << laf << endl;
        int dis2; cin >> dis2;
    }
    return 0;
}
//
// signed main(){
// 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	int n;
// 	cin >> n;
// 	for (int i=1; i<=n-1; i++){
// 		int u,v;
// 		cin >> u >> v;
// 		mp[u].push_back(v);
// 		mp[v].push_back(u);
// 	}
//
// 	return 0;
// }
