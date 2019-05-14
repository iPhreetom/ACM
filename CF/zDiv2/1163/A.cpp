// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	if (n == m)cout << 0 << endl;
	else if(m == 1 || m == 0)cout << 1 << endl;
	else {
		if (m <= n/2) {
			cout << m << endl;
		}
		else {
			m -= n/2;
			cout << n/2 - m + (n%2) << endl;
		}
	}
	return 0;
}
