#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v(212345, 0);
	for (int i=1; i<=n; i++){
		cin >> v[i];
	}

	if(n == 1){
		cout << 1 << endl;
		return 0;
	}

	priority_queue<int> que;
	int cnt = 1;
	int sum = 1;
	for (int i=1; i<=n-1; i++){
		que.push(v[i+1]-v[i]);
		sum += v[i+1]-v[i];
	}
	while(cnt < k) {
		sum -= que.top();
		que.pop();
		cnt++;
		sum++;
	}

	cout << sum << endl;
	return 0;
}
