#include<iostream>
#include<cstdio>
#define int long long
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b;
	cin >> a >> b;
	int r = 1;
	while (r) {
		r = a%b;
		a = b;
		b = r;
	}
	cout << a << endl;
	return 0;
}
