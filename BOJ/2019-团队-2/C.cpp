// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<int,vector<int>,greater<int>> que;
		for (int i=1; i<=n; i++){
			int t;
			cin >> t;
			que.push(t);
		}
		int ans =0;
		while(que.size() >= 2) {
			int a = que.top();
			que.pop();
			int b = que.top();
			que.pop();
			que.push(a+b);
			ans += a+b;
		}
		cout << ans << endl;
	}
	return 0;
}
