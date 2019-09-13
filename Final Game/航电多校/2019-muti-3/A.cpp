// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin >> q;
	while(q--){
		priority_queue<int> que;
		priority_queue<int,vector<int>,greater<int>> que2;
		que2.push(1e18);
		int n,m;
		cin >> n >>m;
		int sum = 0;
		int cnt = 0;
		for (int i=0; i<n; i++){
			int t;
			cin >> t;
			sum += t;
			while (sum > m) {
				sum -= que.top();
				que2.push(que.top());
				que.pop();
				cnt++;
			}

			if (i != n-1)cout << (int)que2.size()-1 << ' ';
			else cout << (int)que2.size()-1 << endl;

			que.push(t);// not chose
			while(que.top() > que2.top()) {
				sum -= (que.top()-que2.top());
				int tp = que.top(); que.pop(); // not chose
				int tp2 = que2.top(); que2.pop(); // chose
				que2.push(tp);
				que.push(tp2);
			}
			while(sum + que2.top() <= m) {
				sum += que2.top();
				que2.pop();
			}
		}
	}
	return 0;
}
