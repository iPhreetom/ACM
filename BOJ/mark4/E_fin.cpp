// CF 796D police station
// 一句话描述：
// 	基于pair的邻接标bfs
// 知识点：
// 	解题思路：去边的题目中，如果可以输出多种答案，有距离限制的bfs，可以不考虑bfs，仍然保存正确
// 	使用pair可以直接保存pair ——> rank
// 		但是没有vector<pair> int——arr 快
// 	典型题目：去边的基本策略是：点去过，而边没有走过。
// 	实现有距离限制的bfs：
// 		使用两个queue
// 		使用一个bool变量
// 		使用一个count，记住最后count==dis时，特判处理
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> pii;

int n,k,d;
int p[312345];
vector<vector<int> > a(312345);
map<pii,int> edge;
map<pii,bool> visedge;
bool vispoint[312345];
queue<int> que;
set<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>d;
	for(int i=0;i<k;i++){
		cin>>p[i];
		que.push(p[i]);
		vispoint[p[i]]=1;
	}

	int v,u;
	pii tp;
	for(int i=1;i<=n-1;i++){
		cin>>v>>u;
		if(v > u)swap(v,u);
		a[u].push_back(v);
		a[v].push_back(u);
		tp = make_pair(v,u);
		edge[tp] = i;
		visedge[tp] = 0;
	}

	while(!que.empty()){
		int tp = que.front();
		// cout<<tp<<endl;
		que.pop();
		for(int i=0;i<a[tp].size();i++){
			if(vispoint[a[tp][i]] == 0){
				que.push(a[tp][i]);
				visedge[make_pair(min(tp,a[tp][i]),max(tp,a[tp][i]))] = 1;
				vispoint[a[tp][i]] = 1;
			}
			else if(visedge[make_pair(min(tp,a[tp][i]),max(tp,a[tp][i]))] == 0){
				ans.insert(edge[make_pair(min(tp,a[tp][i]),max(tp,a[tp][i]))]);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<' ';
	return 0;
}
