#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;


int father[212345];

void init(){
	for (int i=0; i<105; i++){
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

int sum = 0;
priority_queue<pair<int,pair<int,int>>> que;
void klus() {
	 
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin>>n>>m;

	init();
	for (int i=1; i<=m; i++){
		int u,v,x;
		cin>>u>>v>>x;
		a[v].push_back(make_pair(u,x));
		a[u].push_back(make_pair(v,x));
		que.push(make_pair(x,make_pair(u,v)));
	}
	klus();


	return 0;
}
