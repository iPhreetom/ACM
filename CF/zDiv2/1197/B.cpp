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
	vector<int> v(n);
	int indexl = 0;
	int indexr = 0;
	queue<int> lt;
	queue<int> rt;
	for (int i=0; i<n; i++){
		cin >> v[i];
		if (v[i] == n) indexl = indexr = i;
	}
	for (int i=indexr+1; i<n; i++){
		rt.push(v[i]);
	}
	for (int i=indexl-1; i>=0; i--){
		lt.push(v[i]);
	}

	int now = n-1;

	while(!rt.empty() || !lt.empty()) {
		// cout<<"rt.size() = "<<rt.size()<<endl;
		// cout<<"lt.size() = "<<lt.size()<<endl;
		bool can = 0;
		if (!rt.empty()) {
			if (rt.front() == now) {
				can = 1;
				rt.pop();
			}
		}
		if (!lt.empty()) {
			if (lt.front() == now) {
				can = 1;
				lt.pop();
			}
		}
		if (!can) {
			cout << "NO" << endl;
			return 0;
		}
		now--;
	}
	cout << "YES" << endl;
	return 0;
}
