#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
typedef long long LL;
//n![1~10]：1,2,6,24,120,720,5040,40320,362880,3628800,
const int mod=1e6+3;
int prime[4000000];
bool vis[2000005];
int cnt=0;
void init()
{
    int m=sqrt(2000005);
    for(int i=2;i<=m;i++)
    {
        if(!vis[i]){
            for(int j=i*2;j<=2000005;j+=i){
                vis[j]=true;
            }
        }
    }
    for(int i=2;i<=2000000;i++) if(!vis[i]) prime[cnt++]=i;
}
LL poww(LL a,LL b,LL m)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ans;
}
int main()
{
    _xx;
    init();
    int n;
    while(cin>>n){
		if (n == 1) {
			cout << 2 << endl;
			continue;
		}
        LL ans=1;
        for(int i=0;i<cnt && prime[i]<=n;i++){
            int k=0;
            int t=n;
            while(t){
                k+=t/prime[i];
                t/=prime[i];
            }
            ans=ans*poww(prime[i],k,mod)%mod;
        }
        cout<<ans<<endl;
    }
}
