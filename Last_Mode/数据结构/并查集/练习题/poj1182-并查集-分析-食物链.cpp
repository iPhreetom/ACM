// fyt
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
using namespace std;

const int maxn = 151234; // temp

int p[maxn];

void init() {
	for (int i=0; i<maxn; i++){
		p[i] = i;
	}
}

inline int getparent(int v) {
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

int main(){
	init();
	int n, k, ans=0;
	// cin >> n >> k;
	scanf("%d %d", &n, &k);
	for (int i=0; i<k; i++){
		int t,u,v;
		scanf("%d %d %d", &t, &u, &v);
		if (u>n||v>n||v<1||u<1) ans++;
		else {
			if (t == 1) {
				if (ifsame(v,u+n)||ifsame(v,u+2*n)) ans++;
				else {
					unite(u,v);
					unite(u+n,v+n);
					unite(u+n+n,v+n+n);
				}
			}
			else {
				if (u == v) ans++;
				else {
					if (ifsame(u,v) || ifsame(u+n,v)) ans++;
					else {
						unite(u,v+n);
						unite(u+n,v+2*n);
						unite(u+2*n,v);
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
