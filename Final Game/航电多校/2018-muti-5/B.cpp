#include<bits/stdc++.h>
using namespace std;

int T,n,k,s[10],q[10][10];

int main(){
  for (scanf("%d",&T);T;--T){
  	scanf("%d%d",&n,&k);
  	int x=n,tot=0;s[0]=0;
    while (x) s[++s[0]]=x%10,x/=10;
  	for (int i=s[0];i;--i){
  	  int id=i;
  	  for (int j=1;j<i;++j)
  	   if (s[j]<s[id]&&(!(i==s[0]&&s[j]==0)))
		id=j;
  	  if (id!=i) ++tot,swap(s[i],s[id]);
  	  if (tot==k) break;
  	}
  	for (int i=s[0];i;--i) printf("%d",s[i]);
  	printf(" ");
  	tot=0;s[0]=0;
  	while (n) s[++s[0]]=n%10,n/=10;
  	for (int i=s[0];i;--i){
  	  int id=i;
  	  for (int j=1;j<i;++j)
  	   if (s[j]>s[id]) id=j;
  	  if (id!=i) ++tot,swap(s[i],s[id]);
  	  if (tot==k) break;
  	}
  	for (int i=s[0];i;--i) printf("%d",s[i]);
  	printf("\n");
  }
  return 0;
}
