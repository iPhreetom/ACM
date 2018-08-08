#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;
const int inf = 2e9;
typedef pair<int,int> pii;


int t;
int n,m;
vector<pair<int,int> > a[1123456];
vector<pair<int,int> > b[1123456];
int d1[1123456];
int d2[1123456];
// #define inf 112345678
#define maxe 1123456
#define maxv 1123456


int d[maxv];

void dijkstra3(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d1[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int from = p.second;
		if(d1[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<a[from].size();i++){
			int &to = a[from][i].first;
			int &c = a[from][i].second;
			if(d1[to] > d1[from] + c){
				d1[to] = d1[from] + c;
				que.push(make_pair(d1[to],to));
			}
		}
	}
}

void dijkstra4(int s){
	priority_queue<pii,vector<pii>,greater<pii> > que;// 从小到大
	// fill(d1,d1+n+1,inf);
	d2[s] = 0;
	que.push(make_pair(0,s));

	while(!que.empty()){
		pii p = que.top();
		que.pop();

		int from = p.second;
		if(d2[from] < p.first)continue;// 此时这个节点被更新了更小的值，舍弃曾经的最小值45
		for(int i=0;i<b[from].size();i++){
			int &to = b[from][i].first;
			int &c = b[from][i].second;
			if(d2[to] > d2[from] + c){
				d2[to] = d2[from] + c;
				que.push(make_pair(d2[to],to));
			}
		}
	}
}

void init(){
	// a.clear();
	// b.clear();
	// a.resize(n+1);
	// b.resize(n+1);
	for(int i=0;i<=n;i++){
		a[i].clear();
		b[i].clear();
	}
	fill(d1,d1+n+1,inf);
	fill(d2,d2+n+1,inf);
}

void djkstra1(int root){
	priority_queue<pii,vector<pii>,greater<pii> > que;
	d1[root] = 0;
	que.push(make_pair(0,root));


	while(!que.empty()){
		int e = que.top().first;
		int v = que.top().second;
		que.pop();

		if(d1[v] < e)continue;

		for (int i=0; i<a[v].size(); i++){
		    int &to = a[v][i].first;
			int &c = a[v][i].second;
			// cout<<"d1[v]+c = "<<d1[v]+c<<endl;
			if(d1[to] > d1[v]+c){
				d1[to] = d1[v]+c;
				que.push(make_pair(d1[to],to));
			}
		}
	}
}

void djkstra2(int root){
	priority_queue<pii,vector<pii>,greater<pii> > que;
	d2[root] = 0;
	que.push(make_pair(0,root));


	while(!que.empty()){
		int e = que.top().first;
		int v = que.top().second;
		que.pop();

		if(d2[v] < e)continue;

		for (int i=0; i<b[v].size(); i++){
		    int &to = b[v][i].first;
			int &c = b[v][i].second;
			if(d2[to] > d2[v]+c){
				d2[to] = d2[v]+c;
				que.push(make_pair(d2[to],to));
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		init();
		for (int i=0; i<m; i++){
		   int x,y,c;
		   cin>>x>>y>>c;
		   a[x].push_back(make_pair(y,c));
		   b[y].push_back(make_pair(x,c));
		}

		dijkstra3(1);
		dijkstra4(1);

		int ans = 0;
		for (int i=2; i<=n; i++){
			ans+=d1[i];
			ans+=d2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
