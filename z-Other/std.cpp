

#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int mod = 1e9+7,maxdiv = 20;
vector <int> lis;
int n,m;
inline int numof1(int x)
{
	int res=0;
	for(int i=0;i<=maxdiv;i++)
	{
		if(x&(1<<i))res++;
	}
	return res;
}

const int MAXN = 1e4+5;
int prime[MAXN+1];
int minPrime[MAXN+1];

void getPrime(){
    memset(prime, 0, sizeof(prime));
    for (int i=2; i<=MAXN; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            // minPrime[i] = i;
        }
        for(int j=1; j<=prime[0] && prime[j]*i<=MAXN; ++j){
            prime[prime[j]*i] = 1;
            // minPrime[prime[j]*i] = prime[j]; // 获得最小质因数
            if(i % prime[j] == 0) break;
        }
    }
}


inline void split(int m)
{
	for (int i=1; i<=prime[0]; i++){

	}
}

// void split(void)
// {
// 	int tmp = m;
// 	for(int i = 1; prime[i] * prime[i] <= tmp && i<=prime[0]; ++i)
//     {
// 		bool fir = 1;
// 		while(tmp % prime[i] == 0)
//         {
//             tmp /= prime[i];
//             if(fir)
// 			{
// 				fir=1;
// 				lis.push_back(prime[i]);
// 			}
//         }
//     }
//     if(tmp > lis[lis.size()-1])
//         lis.push_back(tmp);
// }

inline void split(){
	for (int i=1; i<=prime[0] && prime[i]*prime[i] <= m; i++){
		if(m%prime[i] == 0){
			lis.push_back(prime[i]);
		}
	}
}

int prod[(1<<maxdiv)+5];//product
inline int cnt(void)
{
	int res=0;
	prod[0]=1;
	for(int s=1;s<(1<<lis.size());s++)
	{
		for(int i=lis.size();i>=0;i--)
		{
			if(s&(1<<i))
			{
				prod[s] = prod[s^(1<<i)] * lis[i];
				if(prod[s] > n)break;//greater than n
				int tmp = n / prod[s];
				int f=(numof1(s)%2==0?-1:1);
				res += f*(prod[s] * (((1+tmp)*tmp%mod*500000004)%mod) % mod);
				res = (res+mod)%mod;
				res += f*(((prod[s] * prod[s])%mod * ((((tmp*(tmp+1))%mod)*(tmp*2+1))%mod)*166666668%mod)%mod);
				res = (res+mod)%mod;
				break;
			}
		}
	}
	return res;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getPrime();
	while(cin>>n>>m){
		n = min(n,m);
		lis.clear();
		memset(prod,0,sizeof(prod));
		int sum = 0;
		split();
		int sum1 = cnt();
		sum = ((1+n)*n)%mod*500000004ll%mod;
		sum %= mod;
		sum = sum + ((((n+1)*n)%mod * (2*n+1))%mod*166666668ll%mod);
		sum %= mod;
		sum = ((sum-sum1)+mod)%mod;
		cout<<sum<<endl;
	}
	return 0;
}
