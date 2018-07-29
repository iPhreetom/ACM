#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> num;
vector<ll> vals;


double InvSqrt (double x)
{
        double xhalf = 0.5f*x;
        ll i = *(ll*)&x;
        i= 0x5f3759df - (i>>1);
        x= *(double*)&i;
        x= x*(1.5f - xhalf*x*x);
        return x;
}

ll Q_rsqrt( ll number )
{
        ll i;
        double x2, y;
        const double threehalfs = 1.5F;

        x2= number * 0.5F;
        y   = number;
        i   = * ( ll * ) &y;   // evil floating point bit level hacking
        i   = 0x5f3759df - ( i >> 1 ); // what thefuck?
        y   = * ( double * ) &i;
        y   = y * ( threehalfs - ( x2 * y * y ) ); //1st iteration
        //y   = y * ( threehalfs - ( x2 * y * y )); // 2nd iteration, this can be removed

        return (ll)y;
}

inline ll root(ll x) {
	register ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		register ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}

void init(){
	// num.push_back(1);

	// for(int i = 2; i <= 1e6; i++) {
    //     int val = InvSqrt(i);
    //     if(val * val == i)
    //         continue;
    //     ll a = 1LL * i * i;
    //     int cnt = 0;
    //     while(a <= 1e18 / i) {
    //         a *= i;
    //         cnt++;
    //         if(cnt & 1)
    //             vals.push_back(a);
    //     }
    // }

	for(int i=2;i<=1e6;i++){
		int val = InvSqrt(i);
        if(val * val == i)
            continue;

		ll t =  1ll * i*i;
		// bug点
		if(t < 0){
			cout<<t<<endl;
			break;
		}
		int cnt=0;
		while(t <= 1e18/i){
			t *= i;
			cnt++;
			// if(InvSqrt(t)*InvSqrt(t)!=t);
			if(cnt & 1)num.push_back(t);
		}
	}

	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	float a = 2.9999999999999999;
	printf("%.10f\n",a);

	for(register ll i=10000000;i<=30000000;i++){
		if((ll)sqrt(i*1e10) != root(i*1e10)){

			// 当两个的值不一样：输出： 原值 ---- 开方后（sqrt）重新平方得到的值（理论上只会变小）
			cout<<(ll)(i*1e10)<<" ---- "<<(ll)sqrt(i*1e10)*(ll)sqrt(i*1e10)<<endl;

			// 系统内置 sqrt  和   基于二分的 整数型开方
			printf("%.3lf ---- %lld\n\n",sqrt(i*1e10),root(i*1e10));

		}
	}

	return 0;
}
