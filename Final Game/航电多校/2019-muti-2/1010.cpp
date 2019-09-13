#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
typedef long long LL;
typedef long long ll;
//n![1~10]：1,2,6,24,120,720,5040,40320,362880,3628800,
long long mod, MOD;
LL prime[5000006];
bool vis[8000009];
int cnt=0;
void init()
{
    int m=sqrt(5000000);
    for(int i=2;i<=m;i++)
    {
        if(!vis[i]){
            for(int j=i*2;j<=5000000;j+=i){
                vis[j]=true;
            }
        }
    }
    for(int i=2;i<=5000000;i++) if(!vis[i]) prime[cnt++]=i;
}
LL poww(LL a,LL b,LL m)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ans;
}

LL getans(int n, int mod){
    if (n == 1) {
        return 2;
    }
    LL ans=1;
    for(int i=0;i<cnt && prime[i]<=n;i++){
        int k=0;
        int t=n;
        while(t){
            k+=t/prime[i];
            t/=prime[i];
        }
        ans=ans*poww(prime[i],k,mod)%mod;
    }
    return ans;
}

// 注意 b = 0, MOD = 1 的情况
LL powMod(ll a, ll b, ll MOD) {
    ll ans = 1;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

// 模数爆int时使用
LL mul(ll a, ll b, ll MOD) {
    ll ans = 0;
    for (a %= MOD; b; b >>= 1) {
        if (b & 1) ans = (ans + a) % MOD;
        a = (a << 1) % MOD;
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


int main()
{
    _xx;
    init();

    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >>p;
        for (ll i=p-1; i>=0; i--) {
            if (isprime(i)) {
                cout<<"i = "<<i<<endl;
                cout << getans(i,p) << endl;
                break;
            }
        }
    }
}
