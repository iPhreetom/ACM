// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;

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
const long long IntMaxn = 1e9+7; //此处为质数
using Int = ModInt<IntMaxn>;


Int exgcd(Int a,Int b,Int &x,Int &y){
    Int result = a;
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        result = exgcd(b,a.x%b.x,y,x);
        y -= (a/b)*x;
    }
    return result;
}

Int a[1123456];

void init(){
	Int t,p;
	for (Int i=1; i.x<1123456; i++){
		exgcd(i,mod,t,p);
		a[i.x] = t;
	}
}

Int qpow(Int a,Int b)//a^b
{
	if(b==0)return 1;
	else if(b.x%2)return (((qpow(a,b/2)*qpow(a,b/2)))*(a));
	else return (qpow(a,b/2)*qpow(a,b/2));
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	Int tt;
	cin>>tt;
	init();
	for(Int cc=1;cc.x<=tt.x;cc++){
		Int n,m,k;
		Int ans = 0;
		cin>>n>>m>>k;
		if(k == 1 && n != 1){
			ans = 0;
		}
		else{
			ans = 1;
			for(Int i=m;i.x>(m-k).x;i--){
				ans *= i;
			}

			for(Int i=2;i.x<=k.x;i++){
				ans *= a[i.x];
			}
			ans *= k;
			ans *= qpow(k-1,n-1);
		}
		cout<<"Case #"<<cc<<": "<<ans<<endl;
	}
	return 0;
}
