#include<bits/stdc++.h>
#define N 200010
#define INF 0x3f3f3f3f
#define eps 1e-10
#define pi 3.141592653589793
#define P 998244353
#define LL long long
#define pb push_back
#define cl clear
#define si size
#define lb lower_bound
#define ub upper_bound
#define mem(x) memset(x,0,sizeof x)
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;

struct dd
{
    int x,y,id;
    bool operator < (const dd d)const
    {
        return x==d.x?y<d.y:x<d.x;
    }
}a[N<<1];

int col[N];

int main()
{
    int T;
    sc(T);
    while(T--)
    {
        int n,m;
        scc(n,m); int cn=0; mem(col);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scc(x,y);
            a[++cn]=dd{x,1,i};
            a[++cn]=dd{y,-1,i};
        }
        sort(a+1,a+cn+1);
        queue<int> q; stack<int> st;
        for (int i=1;i<=m;i++) q.push(i);
        int t=0,k=1,prek=0,pret=0,ans=0;
        while(k<=cn)
        {
            int p=k;
            while(a[p].x==a[k].x)
            {
                if (a[p].y==-1)
                {
                    int r=a[p].id;
                    if (col[r]!=0)
                    {
                        t--;
                        q.push(col[r]);
                    }else col[r]=1;
                }
                if (a[p].y==1)
                {
                    int r=a[p].id;
                    if (t>=m) {st.push(r);} else
                    {
                        t++;
                        col[r]=q.front();
                        q.pop();
                    }
                }
                p++;
            }
            while(t<m)
            {
                while(!st.empty() && col[st.top()]) st.pop();
                if (st.empty()) break;
                t++;
                int r=st.top(); st.pop();
                col[r]=q.front();
                q.pop();
            }
            if (pret>=m) ans+=(a[k].x-prek);
            pret=t;
            prek=a[k].x;
            k=p;
        }
        printf("%d\n%d",ans,col[1]);
        for (int i=2;i<=n;i++) printf(" %d",col[i]); puts("");
    }
}
