// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	priority_queue<int> que;
	int ans = 0;
	for (int i=0; i<n; i++){
		cin >> v[i];
		if (i != 0) {
			que.push(v[i]-v[i-1]);
			ans += v[i]-v[i-1];
		}
	}
	for (int i=1; i<k; i++){
		ans -= que.top();
		que.pop();
	}
	cout << ans << endl;
	return 0;
}
