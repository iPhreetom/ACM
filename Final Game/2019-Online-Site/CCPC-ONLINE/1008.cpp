// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;

		int cnt = n-1;
		int sum = n*k;
		priority_queue<int> que;
		vector<int> v(n);
		for (int i=0; i<n; i++){
			cin >> v[i];
			sum += v[i];
		}

		sort(v.begin(),v.end());
		for (int i=1; i<n; i++){
			que.push(v[i]);
		}

		while(!que.empty() && cnt > 0) {
			int now = que.top();
			que.pop();
			bool flag = 0;
			while (now > k && cnt > 0) {
				cnt--;
				now -= k;
				sum -= k;
				flag = 1;
			}
			if (flag) {
				if (now) que.push(now);
			}
			else {
				sum -= now;
				cnt--;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
