#include <bits/stdc++.h>
#define int long long
using namespace std;

#define int long long
typedef long long LL;
typedef long long ll;

// 模数爆int时使用
LL mul(ll a, ll b, ll MOD) {
	ll ans = 0;
	for (a %= MOD; b; b >>= 1) {
		if (b & 1) ans = (ans + a) % MOD;
		a = (a << 1) % MOD;
	}
	return ans;
}

// 注意 b = 0, MOD = 1 的情况
LL powMod(ll a, ll b, ll MOD) {
    ll ans = 1;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1) ans = mul(ans, a, MOD);
        a = mul(a, a, MOD);
    }
    return ans;
}

// O(logn)
// 前置：快速乘、快速幂
// int范围只需检查2, 7, 61
bool Rabin_Miller(ll a, ll n) {
    if (n == 2 || a >= n) return 1;
    if (n == 1 || !(n & 1)) return 0;
    ll d = n - 1;
    while (!(d & 1)) d >>= 1;
    ll t = powMod(a, d, n);
    while (d != n - 1 && t != 1 && t != n - 1) {
        t = mul(t, t, n);
        d <<= 1;
    }
    return t == n - 1 || d & 1;
}

bool isprime(ll n) {
    static vector<ll> t = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (n <= 1) return false;
    for (ll k : t) if (!Rabin_Miller(k, n)) return false;
    return true;
}

ll inv(ll x, const long long MOD) { return powMod(x, MOD - 2, MOD); }

signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
    cin >> t;
    while (t--) {
        int p;
        cin >>p;
        for (ll i=p-1; i>=0; i--) {
            if (isprime(i)) {
				int sum = p-1;
				for (int j=p-1; j>i; j--) {
					sum = mul(sum,inv(j,p),p);
				}
				cout << sum << endl;
                break;
            }
        }
    }
	unordered_map<int,int> mp;
	return 0;
}
