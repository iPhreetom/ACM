// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	int mx = (1<<31)-1;
	for (int i=1; i<=t; i++){
	    int n;
		cin >> n;
		vector<int> v;
		int c = 1;
		for (int j=1; j<=n; j++){
			int d;
			cin >> d;
			v.push_back(d);
		}
		sort(v.begin(),v.end());
		if (c > mx) {
			cout << -1 << endl;
			continue;
		}
		if (n == 1) c *= 2;
		cout << c << endl;
	}
	return 0;
}
