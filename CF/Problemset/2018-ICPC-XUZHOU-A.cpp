#include<bits/stdc++.h>
#define int unsigned long long
#define double long double
using namespace std;
typedef pair<int,pair<int,int>> pii;

unsigned long long k1,k2;
const int mod = 1e9+7;

unsigned long long xorS() {
	unsigned long long k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3^k4^(k3>>17)^(k4>>26);
	return k2 + k4;
}

int n,m,u[100001],v[100001];
unsigned long long w[100001];
int father[100005];

priority_queue<pii,vector<pii>,greater<pii>> que;

void gen() {
	cin >> n >> m >> k1 >> k2;
	while(!que.empty())que.pop();
	for (int i=1; i<=m; i++){
	    u[i] = xorS()%n + 1;
		v[i] = xorS()%n + 1;
		w[i] = xorS();
		que.push(make_pair(w[i],make_pair(u[i],v[i])));
	}
}


void init(int o){
	for (int i=0; i<=o; i++){
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


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		gen();
		init(n);
		int sum = 0;
		while(!que.empty()) {
			int tw = que.top().first;
			int tu = que.top().second.first;
			int tv = que.top().second.second;
			que.pop();
			if(!same(tu,tv)) {
				unite(tu,tv);
				sum += tw;
				sum %= mod;
			}
		}
		int cnt = 1;
		for (int i=2; i<=n; i++){
			if(same(1,i))cnt++;
		}
		if(cnt == n)cout << sum << endl;
		else cout << 0 << endl;
	}

	return 0;
}
