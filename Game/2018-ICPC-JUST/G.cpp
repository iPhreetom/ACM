// BSGS
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const long long MOD = 1313131;
const long long MAXN = 500000 + 5;
long long gcd(long long x, long long y) { return y ? gcd(y, x%y) : x; }
void Exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        Exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
long long qkpow(long long a, long long b, long long m)//O(logN) a^b%m
{
    long long ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1) ans = (ans*a) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return ans % m;
}
struct Hashset
{
    long long head[MOD], Next[MAXN], f[MAXN], v[MAXN], ind;
    void reset()
    {
        ind = 0;
        memset(head, -1, sizeof head);
    }
    void Insert(long long x, long long _v)
    {
        long long ins = x % MOD;
        for (long long j = head[ins]; j != -1; j = Next[j])
            if (f[j] == x)
            {
                v[j] = min(v[j], _v);
                return;
            }
        f[ind] = x, v[ind] = _v;
        Next[ind] = head[ins], head[ins] = ind++;
    }
    long long operator [] (const long long &x) const
    {
        long long ins = x % MOD;
        for (long long j = head[ins]; j != -1; j = Next[j])
            if (f[j] == x) return v[j];
        return -1;
    }
} S;
long long Solve(long long a, long long b, long long c)
{
    long long d, x, y;
    Exgcd(a, c, d, x, y);
    x = (x + c) % c;
    return x * b % c;
}
long long BSGS(long long C, long long A, long long B, long long p)  // A^x%p=B S.T.(A,p)=1
{
    if (p <= 100)
    {
        long long d = 1;
        for (int i = 0; i < p; ++i)
        {
            if (d == B) return i;
            d = d * A % p;
        }
        return -1;
    }
    else
    {
        long long m = (int)sqrt(p);
        S.reset();
        long long d = 1, Search;
        for (int i = 0; i < m; ++i)
        {
            S.Insert(d, i);
            d = d * A % p;
        }
        for (int i = 0; i * m < p; i++)
        {
            d = qkpow(A, i * m, p) * C % p;
            Search = S[Solve(d, B, p)];
            if (Search != -1) return i * m + Search;
        }
        return -1;
    }
}
int main()
{
    long long a, b, m;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> m;
        long long d = 1;
        bool find = 0;
        for (long long i = 0; i < 100; i++)
        {
            if (d == b)
            {
                cout << i << endl;
                find = 1;
                break;
            }
            d = d * a % m;
        }
        if (find) continue;
        long long t, C = 1, num = 0;
        while ((t = gcd(a, m)) != 1)
        {
            m /= t;
            b /= t;
            C = C * a / t % m;
            num++;
        }
        long long res = BSGS(C, a, b, m);
        if (res == -1) cout << "No Solution" << endl;
        else cout << res + num << endl;
    }
    return 0;
}
