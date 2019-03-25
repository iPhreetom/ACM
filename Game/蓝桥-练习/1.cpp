#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	int com = a*b/__gcd(a,b);
	com = com*c/__gcd(com,c);
	cout << com << endl;
	return 0;
}
