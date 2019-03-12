#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> v(212345, 0);
	int cnt = 0;
	for (int i=1; i<=n; i++){
	    cin >> v[i];
		if(v[i] <= x) cnt++;
	}

	if(x > y) {
		cout << n << endl;
	}
	else {
		cout << (cnt+1)/2 << endl;
	}
	return 0;
}
