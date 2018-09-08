

#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int mod = 1e9+7,maxdiv = 15;
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
set<int> ss;

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
	for (int i=1; i<=prime[0]; i++){
		ss.insert(prime[i]);
	}
}



inline void split(){
	set<int> st;
	for (int i=1; i*i<=m ;i++){
		if(m%i == 0){
			if(ss.count(m/i) != 0){
				st.insert(m/i);
			}
			if(ss.count(i) != 0){
				st.insert(i);
			}
		}
	}
	for(auto i:st){
		lis.push_back(i);
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
			if(s & (1<<i))
			{
				prod[s] = prod[s^(1<<i)] * lis[i];
				if(prod[s] > n)break;//greater than n
				int tmp = n / prod[s];
				int f=(numof1(s)%2==0?-1:1);
				res += f*(prod[s] * 	(((1+tmp)%mod*tmp%mod*500000004)%mod) % mod);
				res = (res+mod)%mod;
				res += f*(((prod[s] * prod[s])%mod * ((((tmp*(tmp+1))%mod)*(tmp*2+1))%mod)*166666668%mod)%mod);
				res = (res+mod)%mod;
				break;
			}
		}
	}
	return res;
}

int duipai(int index){
	int ans = 0;
	for (int i=1; i<=3000; i++){
		if(__gcd(i,index) == 1){
			ans += (i*(i+1));
			ans%=mod;
		}
	}
	return ans;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getPrime();
	// for (int i=3000; i<=300000; i++){
	//     n = 3000;
	// 	m = i;
	// 	lis.clear();
	// 	memset(prod,0,sizeof(prod));
	// 	int sum = 0;
	// 	split();
	// 	int sum1 = cnt();
	//
	//
	// 	sum = ((1+n)*n)%mod*500000004ll%mod;
	// 	sum %= mod;
	// 	sum = sum + ((((n+1)*n)%mod * (2*n+1))%mod*166666668ll%mod);
	// 	sum %= mod;
	// 	sum = ((sum-sum1)+mod)%mod;
	// 	if(sum != duipai(i)){
	// 		cout<<"i = "<<i<<endl;
	// 		cout<<"sum = "<<sum<<endl;
	// 		cout<<"duipai(i) = "<<duipai(i)<<endl;
	// 		break;
	// 	}
	// }
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
