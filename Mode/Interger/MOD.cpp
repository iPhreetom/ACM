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
