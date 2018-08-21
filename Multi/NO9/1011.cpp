// 天才少女
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define row(a, s, e) for(int a = s; a <= e; ++a)
#define wor(a, s, e) for(int a = s; a >= e; --a)
#define rowd(a, s, e, d) for(int a = s; a <= e; a += d)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
// #define MOD (998244353)
#define endl '\n'
const long long MOD = 998244353;

//定义
template<long long MOD>
struct ModInt
{
    long long x;
    ModInt() : x(0) {}
    ModInt(long long x_) { x = (x_ % MOD + MOD) % MOD; }
    ModInt pow(long long n)
    {
        ModInt a = *this, ans = 1;
        while (n)
        {
            if (n & 1) ans *= a;
            n >>= 1;
            a *= a;
        }
        return ans;
    }
    ModInt inv() { return pow(MOD - 2); }
    ModInt operator + (ModInt b) { return ModInt(x + b.x); }
    ModInt operator - (ModInt b) { return ModInt(x - b.x); }
    ModInt operator * (ModInt b) { return ModInt(x * b.x); }
    ModInt operator / (ModInt b) { return ModInt(ModInt(x) * b.inv()); }
    ModInt& operator += (ModInt b) { return *this = *this + b; }
    ModInt& operator -= (ModInt b) { return *this = *this - b; }
    ModInt& operator *= (ModInt b) { return *this = *this * b; }
    ModInt& operator /= (ModInt b) { return *this = *this / b; }
    ModInt& operator ++ () { x++; return *this; }
    ModInt& operator -- () { x--; return *this; }
    ModInt& operator ++ (int) { x++; return *this; }
    ModInt& operator -- (int) { x--; return *this; }
    bool operator == (ModInt b) { return x == b.x; }
    bool operator != (ModInt b) { return x != b.x; }
    friend ostream& operator << (ostream &os, const ModInt &b) { return os << b.x; }
    friend istream& operator >> (istream &is, ModInt &b) { is >> b.x; if (!is) b = ModInt(); return is; }
};
//声明
const long long IntMaxn = 998244353; //此处为质数
using Int = ModInt<IntMaxn>;

Int cf[10000070];

int  main()
{
	cf[0] = 1;
	row(i, 1, 10000050)
	    cf[i] = (cf[i - 1] * 2);
    Int T;
	Int a, b, c, d;
    // scanf("%Intd",&T);
	cin>>T;
    for (int i=0; i<T.x; i++)
    {
        // scanf("%Intd%Intd%Intd%Intd",&a, &b, &c, &d);
		cin>>a>>b>>c>>d;
    	Int ans = 0;
    	//ans += cf[a] - 1;

    	ans += cf[c.x] * cf[a.x];
    	// ans %= MOD;
    	ans += cf[a.x] * (cf[b.x] - 1);
    	// ans %= MOD;
    	ans -= b * cf[a.x];
    	// ans %= MOD;
		// while(ans.x < 0)
    	//     ans += MOD;
    	ans += d * cf[c.x] * cf[a.x];
    	// ans %= MOD;
    	ans += b * cf[c.x] * cf[a.x];
    	// ans %= MOD;

    	// printf("%Intd\n", ans);
		cout<<ans<<endl;
    }
    return 0;
}
