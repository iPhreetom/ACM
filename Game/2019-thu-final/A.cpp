#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,p;
	cin >> n >> m >> p;
	vector<string> v(n);
	for (int i=0; i<v.size(); i++) {
		cin >> v[i];
	}
	vector<string> lis(p);
	for (int i=0; i<p; i++) {
	    cin >> lis[i];
	}
	cout << v[0] << endl;
	return 0;
}
