// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	unsigned int x,a,y,b;
	while(cin >> x >> a >> y >> b) {
		int f1 = 0;
		int f2 = 0;

		f1 = x/a;
		x = x%a;

		f2 = y/b;
		y %= b;

		x = x*b;
		y = y*a;

		if (f1 == f2) {
			if (x > y) {
				cout << ">" << '\n';
			}
			else if(x < y) {
				cout << "<" << '\n';
			}
			else cout << '=' << '\n';
		}
		else {
			if (f1 > f2) {
				cout << ">" << '\n';
			}
			else {
				cout << "<" << '\n';
			}
		}
	}
	return 0;
}
