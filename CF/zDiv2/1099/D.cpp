#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> mp[212345];
int p[212345];
int v[212345];
int mn[212345];
int sum = 0;

int dfs(int p) {
	mn[p] = v[p];
	if(mn[p] == -1)mn[p] = 1e14;
	for (int i=0; i<mp[p].size(); i++){
		int &u = mp[p][i];
		mn[p] = min(dfs(u),mn[p]);
	}
	return mn[p];
}

void getans(int p, int sub) {
	// a[p] = v[p]-sub;
	if(mp[p].size() == 0){
		if(mn[p] == 1e14)return ;
	}

	sum += mn[p]-sub;
	for (int i=0; i<mp[p].size(); i++){
		int &u = mp[p][i];
		getans(u, mn[p]);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	p[1] = 1;
	for (int i=1; i<=n-1; i++){
	    cin >> p[i+1];
		mp[p[i+1]].push_back(i+1);
	}
	for (int i=1; i<=n; i++){
	    cin >> v[i];
	}

	// for (int i=1; i<=n; i++){
	//     if(v[i] == -1) {
	// 		v[i] = v[p[i]];
	// 	}
	// }
	for (int i=1; i<=n; i++){
		if(v[i] != -1 && v[p[p[i]]] > v[i]){
			cout << -1 << endl;
			return 0;
		}
	}

	mn[1] = dfs(1);
	getans(1,0);
	cout << sum << endl;
	return 0;
}


// int sum = 1;
// for (int i=2; i<=n; i++){
	//     int fa = p[i];
	// 	if(v[i] == -1)continue;
	// 	if(fa == 1){
		// 		cout << "-1" << endl;
		// 		return 0;
		// 	}
		// 	fa = p[fa];
		// 	int v1 = v[i];
		// 	int v2 = v[fa];
		// 	if(v2 > v1) {
			// 		cout << "-1" << endl;
			// 		return 0;
			// 	}
			// 	a[i] = v1-v2;
			// 	sum += a[i];
			// }
			// cout << sum << endl;
