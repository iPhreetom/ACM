#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll T,k,m;


int main()
  for (scanf("%I64d",&T);T;--T){
  	scanf("%I64d%I64d",&k,&m);
  	ll n=0,ans=-1;
  	for (int i=0;i<=500;++i){
  	  n=k^i;
  	  ll tot=0;
  	  for (int j=n+1;j<=n+i;++j)
  	   if (__gcd(n,(ll)j)==1) ++tot;

	  if (tot==m&&__gcd(n,i+n)==1){
  	  	if (ans==-1) ans=n;
  	  	else if (n<ans) ans=n;
  	  	break;
  	  }
  	}
  	printf("%I64d\n",ans);
  }
  return 0;
}
