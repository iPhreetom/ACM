#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	while(n -- ) {
		int l, r, d;
		cin >> l >> r >> d;
		if(d >= l) {
			if(d > r) {
				cout << d << endl;
			}
			else {
				int tp = r%d;
				cout << r + d-tp << endl;
			}
		}
		else {
			cout << d << endl;
		}
	}
	return 0;
}
