
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,p1,p2,p3,t1,t2;
pair<int,int> Q[maxn];
int p[3000];
int main()
{
    scanf("%d%d%d%d%d%d",&n,&p1,&p2,&p3,&t1,&t2);
    for(int i=1;i<=n;i++)scanf("%d%d",&Q[i].first,&Q[i].second);
    for(int i=1;i<=n;i++)for(int j=Q[i].first;j<=Q[i].second;j++)
        p[j]=1;
    long long ans = 0;
    int type=0,now=0;
    for(int i=Q[1].first;i<Q[n].second;i++)
    {
        if(p[i]==1)now=0,ans+=p1;
        else if(now>=t1+t2)ans+=p3;
        else if(now>=t1)ans+=p2;
        else ans+=p1;
        now++;
    }
    cout<<ans<<endl;
}
