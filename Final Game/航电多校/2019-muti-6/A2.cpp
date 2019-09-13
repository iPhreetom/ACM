#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Info{
    ll lmax,rmax,max,s;
}T[10007];
vector<int>Li[2007];

int Tt,n,x[2007],y[2007];
int xi[2007],yi[2007],wi[2007];

void Modify(int l,int r,int id,int p,int N){
    if (l==r){
        T[id].s=T[id].max=T[id].lmax=T[id].rmax=N;
        return;
    }
    int lid=id<<1,rid=lid+1,mid=(l+r)>>1;
    if (p<=mid)
     Modify(l,mid,lid,p,N);
    else
     Modify(mid+1,r,rid,p,N);
    T[id].s=T[lid].s+T[rid].s;
    T[id].lmax=max(T[lid].lmax,T[lid].s+T[rid].lmax);
    T[id].rmax=max(T[rid].rmax,T[rid].s+T[lid].rmax);
    T[id].max=max(T[lid].rmax+T[rid].lmax,max(T[lid].max,T[rid].max));
}

int main(){
  for (scanf("%d",&Tt);Tt;--Tt){
      ll ans=-1e9;
    unordered_map<int,int>xh;
    unordered_map<int,int>yh;
      scanf("%d",&n);
      for (int i=1;i<=n;++i){
          scanf("%d%d%d",&xi[i],&yi[i],&wi[i]);
          x[i]=xi[i],y[i]=yi[i];
      }
      sort(x+1,x+n+1);sort(y+1,y+n+1);
      x[0]=unique(x+1,x+n+1)-x-1;
      y[0]=unique(y+1,y+n+1)-y-1;
      for (int i=1;i<=x[0];++i) xh[x[i]]=i;
      for (int i=1;i<=y[0];++i) yh[y[i]]=i;
      for (int i=1;i<=n;++i){
          xi[i]=xh[xi[i]],yi[i]=yh[yi[i]];
          Li[yi[i]].push_back(i);
    }
    for (int i=1;i<=n;++i)
     for (int j=1;j<i;++j)
      if (xi[i]==xi[j]&&yi[i]==yi[j])
       wi[i]+=wi[j],wi[j]=0;
    for (int l=1;l<=y[0];++l){
        for (int r=l;r<=y[0];++r){
         for (int j=0;j<Li[r].size();++j)
          Modify(1,x[0],1,xi[Li[r][j]],wi[Li[r][j]]);
         if (T[1].max>ans) ans=T[1].max;
        }
        for (int i=l;i<=y[0];++i)
         for (int j=0;j<Li[i].size();++j)
          Modify(1,x[0],1,xi[Li[i][j]],0);
    }
    printf("%I64d\n",ans);
    for (int i=1;i<=y[0];++i) Li[i].clear();
  }
  return 0;
}
