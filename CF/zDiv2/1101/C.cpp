#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int father[1e5+5];
int lt[1e5+5];
int rt[1e5+5];
int n;

void init(){
	for (int i=0; i<=n; i++){
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
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int m = 0;
	cin >> m;
	while(m -- ) {
		cin >> n;
		init();
		for (int i=1; i<=n; i++){
			cin >> lt[i] >> rt[i];
		}
		for (int i=2; i<=n; i++){

		}
	}
	return 0;
}
