#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> b;
	vector<int> a;
	stack<int> wei;
	for (int i=0; i<n/2; i++){
	    int t;
		cin >> t;
		if(wei.empty()) {
			a.push_back(0);
			wei.push(t);
		}
		else {
			int tp = max(a.back(), t - min(wei.top(), t));
			a.push_back(tp);
			wei.push(t - tp);
		}
	}
	while(!wei.empty()) {
		a.push_back(wei.top());
		wei.pop();
	}
	for (int i=0; i<a.size(); i++){
		cout << a[i] << ' ';
	}cout << endl;

	return 0;
}
