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
#define int long long
#define double long double
using namespace std;

int fa[105];
int n;
int m;
struct node{
	int len;
	int l;
	int r;
	bool operator < (const node &a) const{
        //按len由小到大排列，如果要由大到小排列，使用“>”即可；
        return a.len < len;
    }
	node(int len ,int l ,int r){
		this->len = len;
		this->l = l;
		this->r = r;
	}
};
priority_queue<node> que;

int findfa(int x){
	int root = x;
	while(fa[root] != root){
		root = fa[root];
	}

	while(x != fa[x]){
		int t = fa[x];
		fa[x] = root;
		x = t;
	}
	return root;
}

bool same(int l,int r){
	return findfa(l) == findfa(r);
}

void unite(int l,int r){
	int x = findfa(l);
	int y = findfa(r);
	if(x == y)return ;

	fa[x] = y;
}

void init(){
	for (int i=0; i<=100; i++){
	    fa[i]=i;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(1){
		init();
		cin>>n;
		if(n == 0)break;
		for (int i=1; i<=n; i++){
		    cin>>m;
			for (int i=0; i<m; i++){
			    int r,len;
				cin>>r>>len;
				que.push(node(len,i,r));
			}
		}
		int ans = 0;
		while(!que.empty()){
			node p = que.top();
			que.pop();

			if(!same(p.l,p.r)){
				unite(p.l,p.r);
				ans += p.len;
			}
		}
	}
	return 0;
}
