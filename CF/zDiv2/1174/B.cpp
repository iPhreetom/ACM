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
	deque<int> odd;
	deque<int> even;
	vector<int> ans;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		if (t%2 == 1) {
			odd.push_back(t);
		}
		else {
			even.push_back(t);
		}
	}
	for (int i=0; i<n; i++){
		if (odd.empty()) {
			ans.push_back(even.front());
			even.pop_front();
		}
		else if (even.empty()) {
			ans.push_back(odd.front());
			odd.pop_front();
		}
		else {

		}
	}
	return 0;
}
