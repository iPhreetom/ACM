// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

typedef __int128 ll;

// O(1)
ll mul(ll a, ll b, ll p) {
    return (ll)(__int128(a) * b % p);
}

// ax + by = gcd(a, b)
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

// 前置：exgcd
ll excrt(vector<ll>&bi,vector<ll>&ai)
{
    // vector mod vector res
    ll x,y,k;
    ll M=bi[0],ans=ai[0];//第一个方程的解特判
    for(int i=1;i<bi.size();i++)
    {
        ll a=M,b=bi[i],c=(ai[i]-ans%b+b)%b;//ax≡c(mod b)
        ll gcd=exgcd(a,b,x,y),bg=b/gcd;
        if(c%gcd!=0) return -1; //判断是否无解，然而这题其实不用

        x=mul(x,c/gcd,bg);
        ans+=x*M;//更新前k个方程组的答案
        M*=bg;//M为前k个m的lcm
        ans=(ans%M+M)%M;
		if(ans > 1e18)return ans;
    }
    return (ans%M+M)%M;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<ll> mod;
	vector<ll> res;
	for (int i=1; i<=n; i++){
		int x, y;
		cin >> x >> y;
		mod.push_back(x);
		res.push_back(y);
	}

	ll ans = 0;
	ans = excrt(mod,res);

	if (ans < 0) {
		cout << "he was definitely lying" << endl;
	}
	else if(ans > (ll)m) {
		cout << "he was probably lying" << endl;
	}
	else {
		int qwq = ans;
		cout << qwq << endl;
	}
	return 0;
}
