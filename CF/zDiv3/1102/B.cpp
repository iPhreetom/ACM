#include<bits/stdc++.h>
// #define int long long
#define double long double
using namespace std;

bool vis[5005][5005];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;

	vector<int> v(212345,0);
	vector<int> ans(212345,0);
	int index = 1;

	for (int i=1; i<=n; i++){
	    cin >> v[i];
	}
	for (int i=1; i<=n; i++){
		int now = index;
		while(vis[ v[i] ][index]){
			index++;
			if(index > k) index -= k;
			if(index == now) {
				cout << "NO" << endl;
				return 0;
			}
		}
		vis[v[i]][index] = 1;
		ans[i] = index;
		index = now + 1;
		if(index > k) index -= k;
	}
	cout << "YES" << endl;
	for (int i=1; i<=n; i++){
		cout << ans[i] << ' ';
	}cout << endl;


	return 0;
}
