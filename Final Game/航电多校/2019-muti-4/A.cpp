// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e5; // temp

int p[maxn];

void init() {
	for (int i=0; i<maxn; i++){
		p[i] = i;
	}
}

int getparent(int v) {
	int root = v;
	while (p[root] != root) {
		root = p[root];
	}
	while (p[v] != v) {
		int temp = p[v];
		p[v] = root;
		v = temp;
	}
	return root;
}

void unite(int u, int v) {
	v = getparent(v);
	p[v] = getparent(u);
}

bool ifsame(int u,int v) {
	return getparent(u) == getparent(v);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// int T;
	// cin >> T;
	// while(T--) {
	// 	init();
	// }
	for (int i=2; i<=100 ; i++){
		init();
		typedef pair<int,pair<int,int>> pii;
		priority_queue<pii,vector<pii>,greater<pii>> que;
		for (int j=1; j<=i; j++){
			for (int k=1; k<j; k++) {
				que.push(make_pair((j&k),make_pair(j,k)));
			}
		}
		int sum = 0;
		while(!que.empty()){
			int mn = que.top().first;
			int u = que.top().second.first;
			int v = que.top().second.second;
			if (!ifsame(u,v)) {
				unite(u,v);
				sum += mn;
			}
			que.pop();
		}
		if(sum != 0){
			cout<<"i = "<<i<<endl;
			cout << sum << endl;
		}
	}
	return 0;
}
