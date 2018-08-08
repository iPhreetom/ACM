HDU 4714
	一句话描述：
		树形……DFS
	知识点：
		对于一些题目，存在情况，没有所谓的最优解，所有的解法得到的结果都是一样的
		所以对于这种，情况，模拟 或者说 贪心，DFS得到答案
	碎碎念：
		(话说我是不是一道树形DP都没认真写过Orz)
		巨烦的G++，卡MLE卡我几天，不过手动扩展栈的操作也是让人惊讶

		貌似题解：
		一棵树，有N个节点，有N-1条边
		如果现在想要通过 删除边 或者 增添边 的方式，使得所有点成环（并且不含多余边）
		最少要多少次操作呢
		这道题，属于一个贪心的题目
		我一开始就看了一下题解，发现可以直接暴力做
		然后写了一个输入时，直接删除过多的边的方法，结果-WA
		然后改成在DFS时，遇到一个度数大于2的节点，就删去前往它的边，
	WA:
		我瞎说的，这道题，果然还是要DP，瞎搞搞对的思路，其实我并不是很懂


#pragma comment(linker, "/STACK:102400000,102400000")
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

// bool vis[11234567];
// queue<int> que;
vector<int> a[1000050];
int d[1000050];
int ans =  0;

void dfs2(int x,int f){
	if(d[f] > 2){
		ans+=2;
		d[x]--;
		d[f]--;
	}
	for (int i=0; i<a[x].size(); i++){
	    if(a[x][i] != f){
			dfs2(a[x][i],x);
		}
	}
	return ;
}

int dfs(int u,int fa)
{
	int v;
	int cnt=0;
	for (int i=0; i<a[u].size(); i++)
	{
		v=a[u][i];
		if (v==fa) continue;
		cnt+=dfs(v,u);
	}
	if (cnt>=2)
	{
		if (u==1) ans+=cnt-2;
		else ans+=cnt-1;
		return 0;
	}
	return 1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		memset(d,0,sizeof(d));
		// memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			a[i].clear();
		}

		ans = 0;

		for (int i=0; i<n-1; i++){
		    int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			d[u]++;
			d[v]++;
		}

		dfs2(1,0);
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
