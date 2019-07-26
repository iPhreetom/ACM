// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const long long MOD = 1e9 + 7;
// 注意 b = 0, MOD = 1 的情况
long long qpow(long long a, long long b)
{
    long long ret = 1;
    for (; b; (a *= a) %= MOD, b >>= 1)
        if (b & 1)
            (ret *= a) %= MOD;
    return ret;
}
long long inv(long long x) { return qpow(x, MOD - 2); }

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	const int mod = 1e9+7;
	while(cin >> n) {
		vector<int> a(n);
		for (int i=0; i<n; i++){
			cin >> a[i];
		}

		int sum = 0;
		for (int i=0; i<n; i++){
			int now = a[i];
			for (int j=0; j<n; j++){
				if (i == j) continue;
				now *= (((a[j]*a[j]-a[i]*a[i])%mod)+mod)%mod;
				now %= mod;
			}
			now *= 2;
			now %= mod;
			now = inv(now);
			sum += now;
			sum %=mod;
		}
		cout << sum << endl;
	}
	return 0;
}
