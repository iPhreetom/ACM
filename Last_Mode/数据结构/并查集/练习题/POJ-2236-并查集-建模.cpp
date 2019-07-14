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
#define int long long
#define double long double
using namespace std;

const int maxn = 1e3+5;

bool rp[maxn];
int p[maxn];
vector<pair<int,int> > v(maxn);

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
	int n,d;
	cin >> n >> d;
	for (int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		v[i+1] = make_pair(x,y);
	}
	char t;
	init();
	while(cin >> t) {
		if (t == 'O') {
			int p;
			cin >> p;
			rp[p] = true;
			for (int i=1; i<=n; i++){
				int q = i;
				int dis = (v[p].first - v[q].first)*(v[p].first - v[q].first);
				dis += (v[p].second - v[q].second)*(v[p].second - v[q].second);
				if (i!=p && rp[i] && dis <= d*d) {
					unite(p,i);
				}
			}
		}
		else {
			int p, q;
			cin >> p >> q;
			if (!rp[p] || !rp[q]) {
				cout << "FAIL" << endl;
				continue;
			}
			int dis = (v[p].first - v[q].first)*(v[p].first - v[q].first);
			dis += (v[p].second - v[q].second)*(v[p].second - v[q].second);
			if (ifsame(p,q)) {
				cout << "SUCCESS" << endl;
			}
			else {
				cout << "FAIL" << endl;
			}
			// if (dis <= d*d) {
			// 	cout << "SUCCESS" << endl;
			// }
		}
	}
	return 0;
}
