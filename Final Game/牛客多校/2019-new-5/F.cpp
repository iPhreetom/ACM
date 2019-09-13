#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[5000];

bitset<5000>mp[5000],s,ans,Now,t;

int n;

void dfs(int x){
    if (x==n){
        if (Now.count()>ans.count())
         ans=Now;
        return;
    }
    if (t.count()+Now.count()<=ans.count()&&ans.count()>0) return;
    if ((Now&mp[x])==Now){
        bitset<5000>k; k=t;
        t&=mp[x];
        Now|=s<<x;
        dfs(x+1);
        Now^=s<<x;
        t=k;
    }
    dfs(x+1);
}

int main(){
  s=1;
  scanf("%d",&n);
  for (int i=0;i<n;++i)
   scanf("%d",&a[i].second),a[i].first=__builtin_popcount(a[i].second);
  sort(a,a+n);s=1;
  for (int i=0;i<n;++i)
   for (int j=0;j<n;++j){
     int x=a[i].second,y=a[j].second;
     if (((x^y)-((x^y)&(-(x^y))))!=0)
      mp[i].flip(j);
   }
  dfs(0);
  printf("%d\n",ans.count());
  for (int i=0;i<n;++i)
   if ((ans&(s<<i)).count()>=1)
    printf("%d ",a[i].second);
printf("\n");
  return 0;
}
