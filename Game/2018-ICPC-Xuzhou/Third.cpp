#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

// map<int,pair<int,int>> mp;
// bool vis[555*555];
typedef pair<int,pair<int,int> > piii;

piii make(int i,int j,int k){
	return make_pair(i,make_pair(j,k));
}

int anc[250010][55];
int fa[250010];
vector <int > tree[250005];
int deep[250010];

void dfs(int x)
{
    anc[x][0]=fa[x];
    for (int i=1;i<=51;i++)
    {
        anc[x][i]=anc[anc[x][i-1]][i-1];//倍增思想的体现。不妨在纸上试着画一棵树，脑补一下QWQ
    }

    for (int i=0;i<tree[x].size();i++)
    {
        if (tree[x][i]!=fa[x])
        {
            int y=tree[x][i];
            fa[y]=x;//记录父亲节点
            deep[y]=deep[x]+1;//记录深度
            dfs(y);
        }
    }
}

// 从一个点开始建树 并加上lca标记 tree为节点fa为父节点anc为倍增标记（值为倍增父节点的点号）
//
// （根节点开始的dfs）

int lca(int x,int y)//查询最近公共祖先
{
    if (deep[x]<deep[y]) swap(x,y);//我们希望X是较深的点。

    for (int i=51;i>=0;i--)//这个循环在完成第一步。
    {
        if (deep[y]<=deep[anc[x][i]]) //不可以丢掉“=“哦Q^Q
        {
            x=anc[x][i];
        }
    }

    if (x==y) return x;//如果Y是X的祖先，就可以直接返回结果了。

    for (int i=51;i>=0;i--)
    {
        if (anc[x][i]!=anc[y][i]) //第二步。
        {
            x=anc[x][i];
            y=anc[y][i];
        }
    }

    return anc[x][0];//注意第二步IF语句的条件。
}

int father[250010];

void init(){
	for (int i=0; i<250010; i++){
	    father[i]=i;
	}
}

int findfather(int x){
	int root=x;
	while(father[root] != root){
		root = father[root];
	}

	while(father[x] != x){
		int t = father[x];
		father[x] = root;
		x = t;
	}
	return root;
}

bool same(int l,int r){
	int x = findfather(l);
	int y = findfather(r);
	return x == y;
}

void unite(int l,int r){
	int x = findfather(l);
	int y = findfather(r);
	if(x == y)return ;

	father[x] = y;
	// ps: some point's father[s..] is't it's root
}


priority_queue<piii> que;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	init();
	cin>>n>>m;
	for (int i=0; i<n; i++){
	    for (int j=0; j<m; j++){
			char ch;
			int cl,cr;
			cin>>ch>>cl>>ch>>cr;
			// mp[i*m+j] = make_pair(cl,cr);
			int from = i*m+j;
			if(from/m < n-1){
				que.push(make(cl,from,from+m));
			}
			if(from%m < m-1){
				que.push(make(cr,from,from+1));
			}
	    }
	}

	while(!que.empty()){
		auto t = que.top();
		auto from = t.second.first;
		auto to = t.second.second;
		que.pop();

		// cout<<"from = "<<from<<' ';
		// cout<<"to = "<<to<<endl;
		if(same(from,to))continue;
		unite(from,to);

		if(from < 0 || to < 0){
            cout<<"SDA"<<endl;
            return 0;
        }

		tree[to].push_back(from);
		tree[from].push_back(to);
	}

	dfs(0);
	int q;
	cin>>q;
	for (int i=1; i<=q; i++){
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		sx = (sx-1)*m + sy -1;
		ex = (ex-1)*m + ey -1;
		// cout<<"sx = "<<sx<<endl;
		// cout<<"ex = "<<ex<<endl;
		int f = lca(sx,ex);
		if(f < 0 || sx < 0 || ex < 0){cout<<"????????????????????"<<endl;break;}
		else cout<<abs(deep[sx]-deep[f]) + abs(deep[ex]-deep[f])<<endl;
	}

	return 0;
}
