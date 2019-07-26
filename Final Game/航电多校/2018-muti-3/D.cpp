// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool isprime(int n) {
	if (n == 1 || n == 2) return true;
	for (int i=2; i<=sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// for (int i=1; i<=100; i++) {
	// 	int sum = 0;
	// 	for (int j=1; j<i; j++){
	// 		if (__gcd(i,j) == 1) sum++;
	// 	}
	// 	if (isprime(sum)) cout << i << endl;
	// }
	// 1 2 3 4 6
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >> n;
		if (n == 1) cout << 5 << endl;
		else {
			cout << n+5  << endl;
		}
	}
	return 0;
}
