// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9+7;
typedef long long ll;

ll qk(ll a, ll b, ll p) {
    ll ans = 1 % p;
    for (a %= p; b; b >>= 1) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
    }
    return ans;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int all = 1;

	for (int i=1; i<=3*n; i++){
		all *= 3;
		all %= mod;
	}

	all -= qk(7LL,n,mod);
	all += mod;
	all %= mod;

	cout << all << endl;

	return 0;
}
