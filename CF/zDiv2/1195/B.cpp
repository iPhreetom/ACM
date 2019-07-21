// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	// int num = 0;
	for (int i=1; i<=n; i++){
		int sum = (1+i)*(i)/2;
		int res = sum-(n-i);
		if (res == k) {
			cout << sum-res << endl;
			return 0;
		}
	}
	return 0;
}
