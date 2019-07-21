// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin >> n) {
		vector<int> v(n);
		vector<int> u(n);
		deque<int> que1;
		deque<int> que2;

		for (int i=0; i<n; i++){
			cin >> v[i];
		}
		for (int i=0; i<n; i++){
			cin >> u[i];
		}
		bool f = 0;
		for (int i=0; i<n; i++){
			if (que1.empty()) {
				que1.push_back(v[i]);
				que2.push_back(u[i]);
			}
			else {
				while(!que1.empty() && que1.back() > v[i]) que1.pop_back();
				que1.push_back(v[i]);
				while(!que2.empty() && que2.back() > u[i]) que2.pop_back();
				que2.push_back(u[i]);
				if (que1.size() != que2.size()) {
					cout << i << endl;
					f = 1;
					break;
				}
			}
 		}
		if (!f) {
			cout << n << endl;
		}
	}
	return 0;
}
