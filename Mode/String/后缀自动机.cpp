#include<bits/stdc++.h>
using namespace std;
#define rank rankk
#define mp make_pair
#define pb push_back
#define xo(a,b) ((b)&1?(a):0)
#define tm tmp
// #define int long long
#define endl '\n'

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const ll INFF=0x3f3f3f3f3f3f3f3fll;
const int MAX=1e5+5;


const int MAXN=100005;
int t1[MAXN],t2[MAXN],c[MAXN];

bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void da(int str[],int sa[],int rank[],int height[],int n,int m)
{
    str[n++]=0;
    int i, j, p, *x = t1, *y = t2;
    //第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i = 0;i < m;i++)c[i] = 0;
    for(i = 0;i < n;i++)c[x[i] = str[i]]++;
    for(i = 1;i < m;i++)c[i] += c[i-1];
    for(i = n-1;i >= 0;i--)sa[--c[x[i]]] = i;
    for(j = 1;j <= n; j <<= 1)
    {
        p = 0;
        //直接利用sa数组排序第二关键字
        for(i = n-j; i < n; i++)y[p++] = i;//后面的j个数第二关键字为空的最小
        for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
        //这样数组y保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for(i = 0; i < m; i++)c[i] = 0;
        for(i = 0; i < n; i++)c[x[y[i]]]++;
        for(i = 1; i < m;i++)c[i] += c[i-1];
        for(i = n-1; i >= 0;i--)sa[--c[x[y[i]]]] = y[i];
        swap(x,y);
        //根据sa和x数组计算新的x数组 swap(x,y);
        p = 1; x[sa[0]] = 0;
        for(i = 1;i < n;i++)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p >= n)break;
        m = p;//下次基数排序的最大值
    }
    int k = 0; n--;
    for(i = 0;i <= n;i++)rank[sa[i]] = i;
    for(i = 0;i < n;i++)
    {
        if(k)k--;
        j = sa[rank[i]-1]; while(str[i+k] == str[j+k])k++; height[rank[i]] = k;
    }
}
int rank[MAXN],height[MAXN];
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
    mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1;i<=n;i++)best[0][i]=i;
    for(int i=1;i<=mm[n];i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    {
        int a=best[i-1][j];
        int b=best[i-1][j+(1<<(i-1))];
        if(RMQ[a]<RMQ[b])best[i][j]=a; else best[i][j]=b;
    }
}
int askRMQ(int a,int b)
{
    int t; t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    a=rank[a];b=rank[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
int t,k,len;
string sts;
int st[MAXN],sa[MAXN];
multiset<int>s;

ll cal(int x)
{
    ll an=0;
    if(x==1)
    {
        an=1LL*len*(len+1LL)/2LL;
        for(int i=1;i<=len;i++)an-=height[i];
    }
    else
    {
        s.clear();
        for(int i=1;i<=x-1;i++)s.insert(height[i]);
        for(int i=x;i<=len;i++)
        {
            int pre=*s.begin();s.erase(s.find(height[i-x+1]));s.insert(height[i]);
//            printf("%d %d!\n",pre,*s.begin());
            an+=max(0,*s.begin()-pre);
        }
    }
    return an;
}


// 用于求出现了K次的字符串有几种
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int k;
    while(cin>>sts)
    {
		cin>>k;
		len = sts.size();
        memset(height,0,sizeof(height));
        for(int i=0;i<len;i++)st[i]=sts[i]-'A'+1;
        da(st,sa,rank,height,len,27);

		ll ans = cal(k)-cal(k+1);

    }
}
