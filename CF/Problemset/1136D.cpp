// fyt
#include<bits/stdc++.h>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;

vector<unordered_set<int>> mp;
vector<bool> vis;
vector<int> v;

void digui (int index) {
	for (int i=index; i>=2; i--){
		if (mp[v[i]].count(v[i-1]) != 0) {
			swap(v[i],v[i-1]);
		}
		else {
			while(1) {
				vis[v[i-1]] = 1;
				digui(i-1);
				if (vis[v[i-1]]) {
					return ;
				}
				else {
					if (mp[v[i]].count(v[i-1]) != 0) {
						swap(v[i],v[i-1]);
						break;
					}
				}
			}
		}
	}
};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int m;
	cin >> m;

	v.resize(n+1, 0);
	for (int i=1; i<=n; i++){
		cin >> v[i];
	}

	mp.resize(n+1);
	while(m -- ) {
		int u,v;
		cin >> u >> v;
		mp[v].insert(u);
	}

	int ans = v[n];
	vis.resize(n+1, 0);


	digui(n);
	for (int i=1; i<=n; i++){
		if(v[i] == ans) {
			cout << n-i << endl;
			break;
		}
	}

	return 0;
}
