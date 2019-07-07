// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x,y,z;
	cin >> x >> y >> z;

	if ((x/z + y/z) < (x+y)/z) {
		int d1 = x-(x/z)*z;
		int d2 = y-(y/z)*z;

		cout << (x+y)/z << ' ' << z-max(d1,d2) << endl;
	}
	else {
		cout << (x+y)/z << ' ' << 0 << endl;
	}
	return 0;
}
