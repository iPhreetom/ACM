#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x,y,z;
	int a,b,c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	int sum1 = x+y+z;
	int sum2 = a+b+c;

	if(sum1 > sum2) {
		cout << "NO" << endl;
		return 0;
	}

	if(x > a) {
		cout << "NO" << endl;
		return 0;
	}

	a -= x;
	if(y > a+b) {
		cout << "NO" << endl;
		return 0;
	}

	if(y+z > a+b+c){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	return 0;
}
