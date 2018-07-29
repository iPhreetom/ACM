// CF 964C alternating sum
// 	一句话描述：
// 		快速幂 与 逆元
// 	知识点：
// 		快速幂实现方法
// 		逆元：
// 			求逆元的方法：记住a * x = 1(%mod)
// 				即：a*x + m*y = gad(a,m);
// 				代码： exgcd（a,mod,x,y）;
// 					return (x+mod)%mod;
// 			求逆元的意义：
// 				https://www.cnblogs.com/dupengcheng/p/5487362.html
// 				把式子中的除法消除，变成乘法
// 			求逆元的坑点：
// 				把式子变形，求逆元时，尽量求正数的逆元


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long mod = 1e9+9;

long long pw1(long long x, long long y, long long mod){
	long long result=1;
	while(y>0){
		if(y & 1)result = result*x%mod;
		x = x*x%mod;
		y >>= 1;
	}
	return result;
}
ll pw(ll a,ll t){
    ll res=1;
    while(t){
        if(t&1) res=res*a%mod;
        a=(a*a)%mod;
        t/=2;
    }
    return (res+mod)%mod;
}

ll ex_gcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;return a;
    }
    ll te=ex_gcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*x;
    return te;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
	ll result = a;
	if(b == 0){
		x = 1;
		y = 0;
	}
	else{
		result = exgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}
	return result;
}
ll NY(ll nu){
    ll x,y;
    ex_gcd(nu,mod,x,y);
    return (x+mod)%mod;
}




int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n,a,b,k;



	cin>>n>>a>>b>>k;
	string ks;
	cin>>ks;



	if(n+1 <= k){
		// force
		long long a0 = 0;
		for(int i=0;i<ks.size();i++){
			if(ks[i] == '+'){
				a0 += ((pw(a,n-i)%mod)*(pw(b,i)%mod)%mod);
				a0 %= mod;
			}
			else{
				a0 -= ((pw(a,n-i)%mod)*(pw(b,i)%mod)%mod);
				a0 %= mod;
			}
		}
		if(a0 < 0)a0+= mod;
		cout<<a0<<endl;
	}
	else{
		// periodic
		long long a0 = 0;
		for(int i=0;i<ks.size();i++){
			if(ks[i] == '+'){
				a0 += (pw(a,n-i)%mod * (pw(b,i)%mod))%mod;
				// a0 += mod;
				a0 %= mod;
			}
			else{
				a0 -= (pw(a,n-i)%mod)*(pw(b,i)%mod)%mod;
				// a0 += mod;
				a0 %= mod;
			}
		}
		// cout<<a0<<endl;
		long long q = (pw(b,k) * pw(NY(a),k))%mod;
		if(q == 1){
			long long ans;
			long long len = (n+1)/k;
			ans = (a0*len)%mod;
			ans += mod;
			ans %= mod;
			cout<<ans<<endl;
		}
		else{
			// long long len = (n+1)/k;
			// long long ans;
			// ll t1 = (a0 * (NY(q-1)%mod))%mod;
			// ll tx = NY(q-1) * a0 %mod;
			// ll ty = (pw(q,len)-1)%mod;
			// ll t2 = (1-pw(q,len))%mod;
			// ans = tx * ty %mod;
			// ans += mod;
			// ans %= mod;
			// 为什么要在求逆元的时候放一个正数呢？

			// 尝试把求的逆元变成一个取模数
			long long len = (n+1)/k;
			long long ans;
			ll t1 = (a0 * (NY(abs(1-q))%mod))%mod;
			ll t2 = (1-pw(q,len))%mod;

			ll tx = NY(abs(1-q)) * a0 %mod;
			ll ty = abs(1-pw(q,len)) %mod;

			ans = tx * ty %mod;
			ans += mod;
			ans %= mod;

			// 解释：
			/*
			此处使用了 等差数列求和公式

			*/

			// BLOG正解：
			// long long t1=NY(q-1)%mod;
			// long long ans = a0;
	   		// ans=(ans* (pw(q,len)-1)%mod)  *t1%mod;
	   		ans=(ans+mod)%mod;
			cout<<ans<<endl;
			// cout<<((((a0*(NY(abs(1-q)%mod)%mod)%mod)*((1-pw(q,(n+1)/k,mod))%mod))%mod)+mod)%mod<<endl;
		}
	}

	return 0;
}
