#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	vector<int> v(n,0);
	for (int i=0; i<n; i++) {
	    cin >> v[i];
	}

	vector<set<int> > mp(n+1);
	for (int i=0; i<m; i++) {
	    int u,v;
		cin >> u >> v;
		mp[u].insert(v);
	}

	set<int> ob;
	for (int i=n-1; i>=0; i++) {

	}

	return 0;
}
