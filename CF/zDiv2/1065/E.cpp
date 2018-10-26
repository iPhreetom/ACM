// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;

const int mod = 998244353;
const int m2 = 499122177;
int n , m , a , f[maxn] , ans;

inline int qp(int a, int b) {
    int rtn = 1;
	int q = mod;
    while (b) {
        if (b & 1) rtn = rtn * a % q;
        a = a * a % q;
        b >>= 1;
    }
    return rtn;
}

inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;    c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}

signed main()
{
	int i;
	ans = 1;
	n = read();
	m = read();
	a = read();
	for (i = 1 ; i <= m ; i++)
	{
		f[i] = read();
		ans = ((qp(a,(f[i]-f[i-1])*2)+mod-qp(a,f[i]-f[i-1]))%mod*m2%mod+qp(a,f[i]-f[i-1]))%mod*ans%mod;
	}
	ans = qp(a,n-f[m]*2)*ans%mod;
	cout << ans << endl;
	return 0;
}
