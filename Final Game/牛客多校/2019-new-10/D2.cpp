#include<bits/stdc++.h>

using namespace std;

using ll = __int128;

ll mul(ll a, ll b, ll p) {
    return (ll)(__int128(a) * b % p);
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// ll excrt(vector<ll>& m, vector<ll>& r) {
//     ll M = m[0], R = r[0], x, y, d;
//
//     for (int i = 1; i < m.size(); i++) {
//         d = exgcd(M, m[i], x, y);
//         if ((r[i] - R) % d)
//             return -1;
//         x = mul(x, (r[i] - R) / d, m[i] / d);
//         R += x * M;
//         M = M / d * m[i];
//         R %= M;
//         if(( R >= 0 ? R : R + M) > 1e18)
//             return (ll)1e18+1;
//     }
//     return R >= 0 ? R : R + M;
// }

ll excrt(vector<ll>& m, vector<ll>& r) {
    ll M = m[0], R = r[0], x, y, d;

    for (int i = 1; i < m.size(); i++) {
        d = exgcd(M, m[i], x, y);
		if ((r[i] - R) % d)
            return -1;
        x = mul(x, (r[i] - R) / d, m[i]/d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
        if ((R >= 0 ? R : R + M) > 1e18)
			return (ll)(1e18 + 12345);
    }
    return R >= 0 ? R : R + M;
}

int main()
{
    ios::sync_with_stdio(false);

    long long n, m;
    cin >> n >> m;

    vector<ll> mo, r;

    for (auto i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        mo.emplace_back(a);
        r.emplace_back(b);
    }

    bool flag = true;
    for (ll i = 0; i < n && flag; i++)
        for (ll j = i + 1; j < n; j++)
        {
            ll x = (long long)(__gcd((long long)mo[i], (long long)mo[j]));
            ll y = (long long)(abs((long long)r[i] - (long long)r[j]));
            if (y % x != 0)
            {
                flag = false;
                break;
            }
        }

    if (!flag)
    {
        cout << "he was definitely lying" << endl;
        return 0;
    }

     long long ans = excrt(mo, r);

    if (ans > m) cout << "he was probably lying" << endl;
    else cout << ans << endl;

    return 0;
}
