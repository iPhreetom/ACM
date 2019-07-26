#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define P 1000000007
#define N 100010
#define LL long long
using namespace std;

struct query{int l,r,block,id;} Q[N];
LL w[N],inv[N],ans[N];

bool cmp(query a,query b)
{
    if (a.block!=b.block) return a.l<b.l;
    if (a.block&1) return a.r<b.r; 
	return a.r>b.r;
}

LL C(int r,int l)
{
    if (r<l) return 0;
	return w[r]*inv[l]%P*inv[r-l]%P;
}

int main()
{
	w[0]=1;w[1]=1;inv[1]=1; inv[0]=1;
	for (int i=2;i<N;i++)
	{
		w[i]=w[i-1]*i%P;
		inv[i]=inv[P%i]*(P-P/i)%P;
	}
	for (int i=2;i<N;i++) inv[i]=inv[i-1]*inv[i]% P;
	int block=sqrt(100000);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	cin>>Q[i].r>>Q[i].l;
    	Q[i].id=i;Q[i].block=Q[i].l/block;
    }
    int l=1,r=1;LL t=2;
    sort(Q+1,Q+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
    	while(l<Q[i].l)
    	{
    		t=(t+C(r,l+1))%P;
    		l++;
    	}
    	while (l>Q[i].l)
    	{
    		l--;
    		t=(t-C(r,l+1)+P)%P;
    	}
    	while (r<Q[i].r)
    	{
    		r++;
    		t=(2*t-C(r-1,l)+P)%P;
    	}
    	while(r>Q[i].r)
    	{
    		t=(t+C(r-1,l))*inv[2]%P;
    		r--;
    	}
    	ans[Q[i].id]=t;
    }
    for (int i=1;i<=n;i++)cout<<ans[i]<<endl;
    return 0;
}
