// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	priority_queue<int> que;
	for (int i=0; i<n; i++){
		int t; cin >> t;
		que.push(t);
	}
	deque<int> dq;
	dq.push_back(que.top());
	que.pop();
	bool l = 1;
	while(!que.empty()) {
		if(l) {
			dq.push_back(que.top());
			l = !l;
		}
		else {
			dq.push_front(que.top());
			l = !l;
		}
		que.pop();
	}

	for(auto i : dq) {
		cout << i << ' ';
	}cout << endl;
	return 0;
}
