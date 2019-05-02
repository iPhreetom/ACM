#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

map<pair<int,int>, set<int>> ans;
vector<set<pair<int,int>>> mp;
vector<vector<set<int> > > lis;



signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	lis.resize(m+1);
	mp.resize(n+1);

	for (int i=0; i<m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		mp[a].insert(make_pair(b,c));
		mp[b].insert(make_pair(a,c));
	}

	map<pair<int,int>,int> ansmp;
	int q;
	cin >> q;
	while (q--) {
		int u,v;
		cin >> u >> v;
		if (u > v) swap(u,v);
		if (anslis.count(make_pair(u,v)) != 0) {
			cout << anslis[make_pair(u,v)] << endl;
			continue;
		}


	}
	return 0;
}
