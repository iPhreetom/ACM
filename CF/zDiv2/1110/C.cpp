#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

map<int,int> mp;
int a[25] = {1,1,5,1,21,1,85,73
	,341,89,1365,1,5461,4681,21845,
	1,87381,1,349525,
	299593,1398101,178481,5592405,1082401};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int op = 0;
	for (int i=2; i<=25; i++){
		mp[(1<<i)-1] = a[op];
		op++;
	}

	int t;
	cin >> t;
	while(t-- ) {
		int n;
		cin >> n;
		int ans = 1;
		bool wa = 0;
		int tp = 0;
		int num = 0;
		for (int i=1; i<=26; i++){
			if(n == (1ll<<i)-1) {
				wa = 1;
				num = i;
				tp = (1ll<<i)-1;
				break;
			}
		}
		if(wa) {
			// cout << 1 << endl;
			// if(num%2 == 0) {
			// 	int sum = 0;
			// 	int sum2 = 0;
			// 	int index = 0;
			// 	bool f = 1;
			// 	while(tp) {
			// 		if(f) {
			// 			sum += (1ll << index);
			// 		}
			// 		else {
			// 			sum2 += (1ll << index);
			// 		}
			// 		index++;
			// 		tp>>=1;
			// 		f = !f;
			// 	}
			// 	cout << min(sum, sum2) << endl;
			// }
			// else {
			// 	cout << 1 << endl;
			// }
			cout << mp[n] << endl;
		}
		else {
			for (int i=1; i<=26; i++){
			    if((1ll<<i)-1 >= n) {
					cout << (1ll<<i)-1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}

// 11101111011
// 00010000100
// & = 0
// ^ = 11111111111


// 1111
// 0110
// & = 0100 = 3 = 21
// ^ = 1011 = 12 = 42
// 101
// 010
// 01
// 10
// 111
// 7 4 3 2 5 16
// 31 15 16 14 17 12 19 11 20 10 21 9 22 8 23 7 24 6 25 5 26 4 27 3 28 2 29
