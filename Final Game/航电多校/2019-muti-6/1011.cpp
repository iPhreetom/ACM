#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=1e9+7;

char c[50007];
int T,n,m,q,w[50007],ws[50007];
ll Bin[50007],f[50007][10][20],p,ans;

void DP(){
	f[w[0]+1][0][0]=1;
	for(int i=w[0];i;--i){
		for (int j=0;j<=9;++j)
		 for (int k=0;k<m;++k){
		 	int t=(k-(j*Bin[w[i]]%m)%m+m)%m;
		 	for (int Num=0;Num<=9;++Num)
		 	 f[i][j][k]+=f[i+1][Num][t];
		 }
	}
}

ll BinMod[50007];
bool dfs(int x,int tot,int res){
	if (x>w[0]){
		printf("%I64d\n",ans);
		return true;
	}
	ll S=0,st=0;
	for (int i=0;i<=9;++i)
	if (f[x][i][res]){
		S+=f[x][i][res];
		if (S>=tot){
			ans+=i*BinMod[w[x]]%Mod;
			ans%=Mod;
			return dfs(x+1,tot-st,(res-i*BinMod[w[x]]+m)%m);
		}
		st+=f[x][i][res];
	}
	return false;
}

int main(){
  BinMod[1]=1;
  for (int i=2;i<=50000;++i)
	 BinMod[i]=(BinMod[i-1]*10)%Mod;
  for (scanf("%d",&T);T;--T){
  	scanf("%d%d%d",&n,&m,&q);
	scanf("%s",c);
	Bin[1]=1;
	w[0]=0;
	p=ans=0;

	for (int i=2;i<=n;++i)
	 Bin[i]=(Bin[i-1]*10)%m;

	for (int i=0;i<n;++i){
	 p=(p*10)%m;ans=(ans*10)%Mod;

	 if (c[i]=='?') w[++w[0]]=n-i;
	 else p=(p+c[i]-'0')%m,ans=(ans+c[i]-'0')%Mod;
    }

    DP();
    for (int i=1;i<=q;++i){
    	ll k,Ans;
		Ans=ans;
    	scanf("%I64d",&k);
    	if (!dfs(1,k,(m-p)%m))
    	 printf("-1\n");
    	ans=Ans;
    }
  }
  return 0;
}
