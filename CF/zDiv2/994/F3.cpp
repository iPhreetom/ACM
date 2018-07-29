#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 60
#define ll long long

using namespace std;

int n,a[N],c[N],top;
ll f[N][N],ans;
struct node{int a;ll v;}d[N];
bool cmp(node a,node b){return a.a>b.a || (a.a==b.a && a.v>b.v);}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);

    long long h=1,t=1e13,m,res=t+1;
    while(h<=t){
        m=(h+t)/2;ans=1e18;
        for(int i=1;i<=n;i++)d[i]=(node){a[i],a[i]*(ll)10000-m*c[i]};
        sort(d+1,d+n+1,cmp);

        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j]=1e18;
        f[0][0]=0.0;
		int k=0;
		ll sum=d[1].v;
		dec=0;

        for(int i=1,r=0;i<=n;sum+=d[++i].v)
			if(d[i].a!=d[i+1].a){
	            ++k;   
	            for(int x=0;x<=r;x++,dec=0)for(int y=0;y<=x && y<=i-r;y++){
	                if(y)dec+=d[r+y].v;f[k][x-y+i-r-y]=min(f[k][x-y+i-r-y],f[k-1][x]+sum-dec);
	            }
	            r=i;sum=0;
	        }
        for(int i=0;i<=n;i++)
			ans=min(ans,f[k][i]);

		if(ans<=0)res=m,t=m-1;
		else h=m+1;
    }printf("%I64d",(res+9)/10);
    return 0;
}
