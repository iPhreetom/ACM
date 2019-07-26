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

int p[1123456];

void init(int n) {
	for (int i=1; i<=n; i++){
		p[i] = i;
	}
}

int getparent(int v) {
	int root = v;
	while(root != p[root]) {
		root = p[root];
	}
	while(v != p[v]) {
		int tmp = p[v];
		p[v] = root;
		v = tmp;
	}
	return root;
}

bool ifsame(int u,int v) {
	return getparent(v) == getparent(u);
}

int unite(int u, int v) {
	p[getparent(u)] = getparent(v);
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	int cnt = 0;
	while(true){
		cnt++;
		cin >> n >> m;
		// scanf("%d %d",&n,&m);
		if (m == 0 && n == 0) break;
		init(n);
		while(m--){
			int u,v;
			cin >> u >> v;
			// scanf("%d %d",&u,&v);
			unite(u,v);
		}

		int ans = 0;
		set<int> st;
		for (int i=1; i<=n; i++) {
			st.insert(getparent(i));
		}
		cout << "Case " << cnt << ": " << st.size() << '\n';
	}
 	return 0;
}
