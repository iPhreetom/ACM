#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

const long long maxl = 1123456;
bool prime[maxl];
long long ans=0,len=0,x;

void init(){
	for(register long long i=0;i<maxl;i++){
		prime[i]=1;
		// if(i%(maxl/10)==0)cout<<i<<endl;
	}
	for(long long i=2;i*i<maxl;i++){
		if(prime[i]){
			for(long long j=i*2;j<maxl;j+=i){
				prime[j] = 0;
			}
		}
	}
}


typedef long long ll;
int main1(){
    ll x[25]={1};
    for(ll i=1;i<25;++i)
    {
        x[i]=i*x[i-1];
    }
    ll n;
    while(~scanf("%lld",&n))
    {
        ll ans=0,base=1;
        for(ll i=2;i*i<=n;++i)
        {
            if(n%i==0)
            {
                ll cnt=0;
                while(n%i==0)
                {
                    ++cnt;
                    n/=i;
                }
                ans+=cnt;
                base*=x[cnt];
            }
        }
        if(n>1)
        {
            ans+=1;
        }
        printf("%lld %lld\n",ans,x[ans]/base);
    }
    return 0;
}

vector<long long> lis;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();


	while(~scanf("%lld",&x)){
		lis.clear();
		for(int i=2;i<=x;i++){
			if(prime[x]){//此处不优化会TLE
				lis.push_back(x);
				break;
			}
			if(x == 0)break;
			if(prime[i]){
				while(x!=0 && x%i == 0){
					lis.push_back(i);
					x/=i;
				}
			}
		}
		unsigned long long num=1;
		for(unsigned long long i=1;i<=lis.size();i++){
			num*=i;
		}

		long long tp=lis[0];
		unsigned long long count = 1;
		for(long long i=0;i<lis.size();i++){
			if(tp == lis[i]){
				num /= count;
				count++;
			}
			else{
				count = 2;
				tp = lis[i];
			}
		}

		cout<<lis.size()<<' '<<num<<endl;
	}
	//main1();
	return 0;
}
