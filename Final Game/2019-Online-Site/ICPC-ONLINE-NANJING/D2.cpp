// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double ans = 0;

	for (int i=1; i<=10; i++) {
		ans += i*(1.0/pow(4,i));
	}

	cout << ans << endl;
	return 0;
}
