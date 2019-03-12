#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=1000; i<=1010; i++) {
		cout << "i = " << i << endl;
		cout << i*i - (i-1)*(i-1) << endl;
		cout << (i-1)*(i-1) - (i-2)*(i-2)<< endl;
	}
	cout << 33*33 + 33*33 + 33*33 + 33*(7) <<endl;
	cout << 99*99 << endl;

	
	return 0;
}
