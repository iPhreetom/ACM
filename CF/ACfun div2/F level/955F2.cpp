#include<bits/stdc++.h>
#define mod 1000000007
#define LL long long
#define N 100010

using namespace std;

struct query{int l,x,id;} Q[N];
int a[N],n,q,t,ans[N];
vector<int> num;
bool v[1<<20];

bool cmp(query a,query b)
{
    return a.l<b.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=q;i++)
    {
        cin>>Q[i].l>>Q[i].x;
        Q[i].id=i;
    }
    sort(Q+1,Q+1+q,cmp);

    t=v[0]=1;
    num.push_back(0);
    for(int i=1,j=1;i<=n&&j<=q;i++)
    {
        if (!v[a[i]])
        {
            v[a[i]]=1;
            int sz=num.size();                        //这里千万不能边加边扩大循环范围
            for(int k=0;k<sz;k++)
            {
                num.push_back(num[k]^a[i]);
                v[num.back()]=1;
            }
        }
		else t=(t<<1)%mod;

		for (;Q[j].l==i&&j<=q;j++)
            ans[Q[j].id]=t*v[Q[j].x];
    }

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}
