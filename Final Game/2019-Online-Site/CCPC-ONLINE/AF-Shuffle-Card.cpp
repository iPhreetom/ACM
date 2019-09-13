// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool vis[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> lis;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		lis.push_back(t);
	}
	stack<int> st;
	while(m--){
		int t;
		cin >> t;
		st.push(t);
	}

	while(!st.empty()){
		if (!vis[st.top()]) {
			cout << st.top() << ' ';
			vis[st.top()] = 1;
		}
		st.pop();
	}
	for (int i=0; i<lis.size(); i++){
	    if(!vis[lis[i]]) {
			vis[lis[i]] = 1;
			cout << lis[i] << ' ';
		}
	}
	return 0;
}
