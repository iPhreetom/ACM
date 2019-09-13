// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int mn = 1e9;
int val[112];
int n;
vector<pair<int,int>> st;

int check(int x,int y,int z) {
	int mx = 0;
	for (int i=1; i<=n; i++){
		int once = 1e9;
		for (auto get:st) {
			if ((val[i] - get.first)%100 == 0) {
				once = min(once, get.second + (val[i] - get.first)/100);
			}
		}
		mx = max(mx,once);
	}
	return mx;
}

void dfs(int x, int y, int z) {
	if (x>=2 || y>=4 || z>=2) {
		return;
	}

	st.clear();
	for (int i=0; i<=x; i++){
		for (int j=0; j<=y; j++){
			for (int k=0; k<=z; k++) {
				st.emplace_back(i*10 + j*20 + k*50,x+y+z);
			}
		}
	}

	mn = min(mn,check(x, y, z));
	dfs(x+1,y,z);
	dfs(x,y+1,z);
	dfs(x,y,z+1);
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		mn = 1e9;
		bool can = 1;
		for (int i=1; i<=n; i++){
			cin >> val[i];
			if (val[i] % 10 != 0) can = 0;
		}
		if (!can) {cout << -1 << endl; continue;}
		dfs(0,0,0);
		cout << mn << endl;
	}
	return 0;
}
