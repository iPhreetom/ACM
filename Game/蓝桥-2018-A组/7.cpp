#include<bits/stdc++.h>
#define rep(i,x,y) for(register int i=(x);i<=(y);i++)
#define dwn(i,x,y) for(register int i=(x);i>=(y);i--)
#define maxn 1000010
#define LL long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    int f=0;char ch[20];
    if(!x){putchar('0'),putchar('\n');return;}
    if(x<0)x=-x,putchar('-');
    while(x)ch[++f]=x%10+'0',x/=10;
    while(f)putchar(ch[f--]);
    putchar('\n');
}
LL qh[maxn],a[maxn],s[maxn],d[maxn];
int qxa[maxn],qya[maxn],qza[maxn],qxb[maxn],qyb[maxn],qzb[maxn],A,B,C,m,ans;
int getx(int x,int y,int z){return (x*B+y)*C+z+1;}
void getp(int x,int px,int py,int pz){x--;pz=x%C,x/=C,py=x%B,pz=x/B;return;}
void add(int x,int y,int z,LL h){if(x<=(A-1)&&y<=(B-1)&&z<=(C-1))a[getx(x,y,z)]+=h;}
void atk(int xa,int ya,int za,int xb,int yb,int zb,LL h)
{
    add(xa,ya,za,h),add(xa,ya,zb+1,-h),add(xa,yb+1,za,-h),add(xa,yb+1,zb+1,h);
    add(xb+1,ya,za,-h),add(xb+1,ya,zb+1,h),add(xb+1,yb+1,za,h),add(xb+1,yb+1,zb+1,-h);
}
int check()
{
    rep(i,0,A-1)rep(j,0,B-1)rep(k,0,C-1)s[getx(i,j,k)]=a[getx(i,j,k)];
    if(C!=1)rep(i,0,A-1)rep(j,0,B-1)rep(k,1,C-1)s[getx(i,j,k)]+=s[getx(i,j,k-1)];//,cout<<i<<" "<<j<<" "<<k<<"+1 "<<s[getx(i,j,k-1)]<<endl;
    if(B!=1)rep(i,0,A-1)rep(j,1,B-1)rep(k,0,C-1)s[getx(i,j,k)]+=s[getx(i,j-1,k)];//,cout<<i<<" "<<j<<" "<<k<<"+2 "<<s[getx(i,j-1,k)]<<endl;
    if(A!=1)rep(i,1,A-1)rep(j,0,B-1)rep(k,0,C-1)s[getx(i,j,k)]+=s[getx(i-1,j,k)];//,cout<<<<"+3 "<<s[getx(i-1,j,k)]<<endl;
    rep(i,0,A-1)rep(j,0,B-1)rep(k,0,C-1)if(s[getx(i,j,k)]>d[getx(i,j,k)])return 1;
    return 0;
}
void getans(int L,int R,int lastmid)
{
    if(L>R)return;
    int mid=(L+R)>>1;
    if(mid>lastmid)rep(i,lastmid+1,mid)/*cout<<"mid:"<<mid<<" add:"<<i<<endl,*/atk(qxa[i],qya[i],qza[i],qxb[i],qyb[i],qzb[i],qh[i]);
    if(mid<lastmid)rep(i,mid+1,lastmid)/*cout<<"mid:"<<mid<<" del:"<<i<<endl,*/atk(qxa[i],qya[i],qza[i],qxb[i],qyb[i],qzb[i],-qh[i]);
    int f=check();
    //cout<<"mid:"<<mid;
    //cout<<"now:";
    //rep(i,0,A-1)rep(j,0,B-1)rep(k,0,C-1)cout<<s[getx(i,j,k)]<<" ";cout<<endl;
    if(f){ans=min(ans,mid);getans(L,mid-1,mid);}
    else getans(mid+1,R,mid);
}
int main()
{
    //freopen("attack.in","r",stdin);
    //freopen("attack.out","w",stdout);
    A=read(),B=read(),C=read(),ans=m=read();
    rep(i,0,A-1)rep(j,0,B-1)rep(k,0,C-1)d[getx(i,j,k)]=read();
    rep(i,1,m)qxa[i]=read()-1,qxb[i]=read()-1,qya[i]=read()-1,qyb[i]=read()-1,qza[i]=read()-1,qzb[i]=read()-1,qh[i]=read();
    getans(1,m,0);
    write(ans);
    return 0;
}
/*
2 2 2 3
1 1 1 1 1 1 1 1
1 2 1 2 1 1 1
1 1 1 2 1 2 1
1 1 1 1 1 1 2
*/
