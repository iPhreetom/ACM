// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[512345];
bool vis[512345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	priority_queue<int,vector<int>,greater<int>> que;
	for (int i=0; i<n; i++){
		int t; cin >> t;
		a.push_back(t);
		que.push(t);
	}

	vector<int> b;
	for (int i=0; i<n; i++){
		int t; cin >> t;
		b.push_back(t);
	}

	sort(b.begin(),b.end());
	for (int i=0; i<b.size(); i++){
		if (b[i] > que.top()) {
			mp[que.top()].push_back(b[i]);
			que.pop();
			vis[b[i]] = 1;
		}
	}
	int index = 0;
	for (int i=0; i<a.size(); i++) {
		if (!mp[a[i]].empty()) {
			sort(a.rbegin(),a.rend());
		}
	}

	return 0;
}
