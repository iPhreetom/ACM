#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<int> a(212345,0);
	vector<int> c(212345,0);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	for (int i=1; i<=n; i++){
		cin >> c[i];
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	for (int i=1; i<=n; i++){
		que.push(make_pair(c[i],i));
	}
	while(m -- ) {
		int k, d;
		cin >> k >> d;
		int sum = 0;
		if(a[k] >= d) {
			a[k] -= d;
			sum = c[k]*d;
		}
		else {
			sum += c[k]*a[k];
			d -= a[k];
			a[k] = 0;
			// small
			while(d && !que.empty()) {
				int cs = que.top().first;
				int num = que.top().second;
				if(a[num] >= d) {
					sum += c[num]*d;
					a[num] -= d;
					d = 0;
				}
				else {
					sum += c[num]*a[num];
					d -= a[num];
					a[num] = 0;
					que.pop();
				}
			}

			if(d && que.empty()) {
				sum = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
