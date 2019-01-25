// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;



int tt;
set<int> s;
map<string,int> str;

// 求一个无向图的最大团数。
const int maxn = 55;
bool mp[maxn][maxn];
int best, n, num[maxn];
bool dfs(int *adj, int total, int cnt)
{
	int t[maxn], k;
	if(total == 0)
	{
		if(cnt > best)
		{
			best = cnt;
			return true;	//剪枝4
		}
		return false;
	}
	for(int i = 0; i < total; ++i)
	{
		if(cnt+total-i <= best) return false;	//剪枝1
		if(cnt+num[adj[i]] <= best) return false;	//剪枝3
		k = 0;
		for(int j = i+1; j < total; ++j)
		if(mp[adj[i]][adj[j]]) t[k++] = adj[j];
		//扫描与u相连的顶点中与当前要选中的adj[i]相连的顶点adj[j]并存储到数组t[]中，数量为k
		if(dfs(t, k, cnt+1)) return true;
	}
	return false;
}
int MaximumClique()
{
	int adj[maxn], k;
	best = 0;
	for(int i = n; i >= 1; --i)
	{
		k = 0;
		for(int j = i+1; j <= n; ++j)
		if(mp[i][j]) adj[k++] = j;
		//得到当前点i的所有相邻点存入adj
		dfs(adj, k, 1);	//每次dfs相当于必选当前i点看是否能更新best
		num[i] = best;
	}
	return best;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>tt>>n;

	int ans = 0;
	bool first = 1;
	int index = 0;

	for (int i=1; i<=tt; i++){
		int t;
		cin>>t;
		if(t == 1){
			if(first) {
				first = !first;
			}
			else{
				for(auto i:s) {
					for(auto j:s) {
						if(i == j)continue;
						mp[i][j] = 1;
						mp[j][i] = 1;
					}
				}
				s.clear();
			}
		}
		else {
			string name;
			cin>>name;
			if(str[name] == 0){
				str[name] = ++index;
			}
			s.insert(str[name]);
		}
	}
	for(auto i:s) {
		for(auto j:s) {
			if(i == j)continue;
			mp[i][j] = 1;
			mp[j][i] = 1;
		}
	}
	s.clear();

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			// if(i == j)continue;
			mp[i][j] = !mp[i][j];
			// cout<<!mp[i][j]<<' ';
		}
		// cout<<endl;
	}

	cout<<MaximumClique()<<endl;
	return 0;
}
