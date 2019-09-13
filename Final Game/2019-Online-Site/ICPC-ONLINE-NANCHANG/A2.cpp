// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int phi(int x) {
	int res = x, a = x;
	for (int i = 2; i*i <= a; i++)
		if (a%i == 0)
		{
			res = res / i * (i - 1);
			while (a%i == 0) a /= i;
		}
	if (a > 1) res = res / a * (a - 1);
	return res;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;

	while (T--) {
		vector<int> lis;
		for (int i=0; i<100; i++){
			int a; cin >> a;
			lis.push_back(a);
		}
	}
	return 0;
}
