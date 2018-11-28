#include<bits/stdc++.h>
#define int64 long long
using namespace std;
char a[310][310];
int n,m,t[310],b[610][27],c[310][27],r[610];
int64 ans;

void manacher(int n){
	for(int mx=0,i=1,c=0;i<=n;i++){
		r[i]=i<mx?min(r[2*c-i],mx-i):1;
		while(!memcmp(b[i+r[i]],b[i-r[i]],sizeof b[0]))r[i]++;
		if(i+r[i]>mx)mx=i+r[i],c=i;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf(" %c",a[i]+j);
	for(int j=1;j<=m;j++){
		memset(t,0,sizeof t);
		memset(c,0,sizeof c);
		memset(b,0,sizeof b);
		for(int k=j;k<=m;k++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				t[i]^=1<<a[i][k]-'a';
				c[i][a[i][k]-'a']++;
				if(!(t[i]&t[i]-1))
					memcpy(b[i*2],c[i],sizeof c[i]);
				else b[i*2][0]=1e4+cnt++;
			}
			memset(b[0],1,sizeof b[0]);
			memset(b[n*2+2],2,sizeof b[n*2+2]);
			manacher(n*2+1);
			for(int i=1;i<=n;i++)if(!(t[i]&t[i]-1))
				ans+=r[i*2]/2;
			for(int i=1;i<=2*n+1;i+=2)ans+=r[i]/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
