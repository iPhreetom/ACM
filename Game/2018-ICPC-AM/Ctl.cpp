#include<bits/stdc++.h>
using namespace std;
const int N=1100005;
const int MAX=1<<30;
const int M=1001;
typedef long long LL;
int n,nn,m,k;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct qq
{
    int l,r;//管理的范围
    int s1,s2;
    int maxx,minn;
    LL sum;//最大值   最小值   和
    int add;//区间加
    int same;//是否全部变为某个数
    int id;//叶子节点的编号
}tr[M][M*2];//块   线段树
int num;
int cnt,L[M],R[M],belong[N];
struct qt
{
    int x,id;
}a[M];
void update (int now,int lalal)
{
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    tr[now][lalal].maxx=max(tr[now][s1].maxx,tr[now][s2].maxx);
    tr[now][lalal].minn=min(tr[now][s1].minn,tr[now][s2].minn);
    tr[now][lalal].sum=tr[now][s1].sum+tr[now][s2].sum;
    return ;
}
void bt (int now,int l,int r)//哪一个块   坐标
{
    int lalal=++num;
    tr[now][lalal].same=MAX;    tr[now][lalal].add=0;
    tr[now][lalal].l=l;tr[now][lalal].r=r;
    if (l==r)
    {
        tr[now][lalal].maxx=a[l].x;
        tr[now][lalal].minn=a[l].x;
        tr[now][lalal].sum=a[l].x;
        tr[now][lalal].id=a[l].id;
        return ;
    }
    int mid=(l+r)>>1;
    tr[now][lalal].s1=num+1;bt(now,l,mid);
    tr[now][lalal].s2=num+1;bt(now,mid+1,r);
    update(now,lalal);
}
bool cmp (qt a,qt b){return a.x==b.x?a.id<b.id:a.x<b.x;}
void prepare()
{
    L[1]=1;belong[1]=1;cnt=1;
    for (int u=1;u<=n;u++)
    {
        belong[u]=cnt;
        if (u%nn==0)
        {
            R[cnt]=u;
            cnt++;
            L[cnt]=u+1;
        }
    }
    cnt=belong[n];R[cnt]=n;

    for (int u=1;u<=cnt;u++)
    {
        int ooo=0;
        for (int i=L[u];i<=R[u];i++)
        {
            a[++ooo].x=0;
            a[ooo].id=ooo;
        }
        sort(a+1,a+1+ooo,cmp);
        num=0;bt(u,1,ooo);
    }
}
int p[N];
void Add (int now,int lalal,int y)//这个块区间加
{
    if (tr[now][lalal].same!=MAX)
        tr[now][lalal].same+=y;
    else tr[now][lalal].add+=y;
    tr[now][lalal].maxx+=y;
    tr[now][lalal].minn+=y;
    tr[now][lalal].sum=tr[now][lalal].sum+(tr[now][lalal].r-tr[now][lalal].l+1)*(LL)y;
}
void Same (int now,int lalal,int x)//将这个点都变为x
{
    tr[now][lalal].maxx=x;
    tr[now][lalal].minn=x;
    tr[now][lalal].sum=(tr[now][lalal].r-tr[now][lalal].l+1)*(LL)x;
    tr[now][lalal].add=0;
    tr[now][lalal].same=x;
    return ;
}
void push_down (int now,int lalal)//下传标记
{
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    if (tr[now][lalal].same!=MAX)
    {
        int shen=tr[now][lalal].same;tr[now][lalal].same=MAX;
        Same(now,s1,shen);Same(now,s2,shen);
    }
    else if (tr[now][lalal].add!=0)
    {
        int shen=tr[now][lalal].add;tr[now][lalal].add=0;
        Add(now,s1,shen);Add(now,s2,shen);
    }
}
void rebuild (int now,int lalal)//重建这个块  并把重建后的东西放在p数组
{
    if (tr[now][lalal].l==tr[now][lalal].r)//如果已经到了叶子节点
    {
        p[tr[now][lalal].id]=tr[now][lalal].sum;
        return ;
    }
    push_down(now,lalal);
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    rebuild(now,s1);rebuild(now,s2);
}
qt A[N];int KO;
void rebuild1 (int now,int lalal)//重建这个块   然后把叶子的信息都放在A数组里面
{
    if (tr[now][lalal].l==tr[now][lalal].r)//如果已经到了叶子节点
    {
        A[++KO].x=tr[now][lalal].sum;
        A[KO].id=tr[now][lalal].id;
        return ;
    }
    push_down(now,lalal);
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    rebuild1(now,s1);rebuild1(now,s2);
}
queue<qt> q1;
qt B[N];
void ADD (int l,int r,int x)//l到r都加上x
{
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
        l=l-L[lp]+1;r=r-L[lp]+1;
        KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
        int lalal=0;
        for (int u=1;u<=KO;u++)
            if (A[u].id<l||A[u].id>r)
                B[++lalal]=A[u];//可行
            else    q1.push(A[u]);
        int ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            while (!q1.empty())
            {
                qt xx=q1.front();
                if (xx.x+x<=B[u].x)
                {
                    q1.pop();
                    a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
                }
                else break;
            }
            a[++ooo]=B[u];
        }
        while (!q1.empty())
        {
            qt xx=q1.front();q1.pop();
            a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
        }
        num=0;bt(lp,1,ooo);
        return ;
    }
    for (int u=belong[l]+1;u<belong[r];u++)     Add(u,1,x);
    /*更新l这个块*/
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
    int lalal=0;
    for (int u=1;u<=KO;u++)
        if (A[u].id<ll||A[u].id>rr)
            B[++lalal]=A[u];//可行
        else    q1.push(A[u]);
    int ooo=0;
    for (int u=1;u<=lalal;u++)//吧每一个数都放进去
    {
        while (!q1.empty())
        {
            qt xx=q1.front();
            if (xx.x+x<=B[u].x)
            {
                q1.pop();
                a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
            }
            else break;
        }
        a[++ooo]=B[u];
    }
    while (!q1.empty())
    {
        qt xx=q1.front();q1.pop();
        a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
    }
    num=0;bt(lp,1,ooo);
    /*更新l这个块*/
    /*更新r这个块*/
    ll=1,rr=r-L[rp]+1;
    KO=0;rebuild1(rp,1);//得到了一个有序的叶子信息
    lalal=0;
    for (int u=1;u<=KO;u++)
        if (A[u].id<ll||A[u].id>rr)
            B[++lalal]=A[u];//可行
        else    q1.push(A[u]);
    ooo=0;
    for (int u=1;u<=lalal;u++)//吧每一个数都放进去
    {
        while (!q1.empty())
        {
            qt xx=q1.front();
            if (xx.x+x<=B[u].x)
            {
                q1.pop();
                a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
            }
            else break;
        }
        a[++ooo]=B[u];
    }
    while (!q1.empty())
    {
        qt xx=q1.front();q1.pop();
        a[++ooo].id=xx.id,a[ooo].x=xx.x+x;
    }
    num=0;bt(rp,1,ooo);
    /*更新r这个块*/
}
void up1 (int now,int lalal,int x)//将这一个块小于x都变为x
{
    if (tr[now][lalal].maxx<=x)//这一段都要变为x了
    {
        Same(now,lalal,x);
        return ;
    }
    if (tr[now][lalal].minn>=x)//最小都GG
        return ;
    if (tr[now][lalal].l==tr[now][lalal].r) return ;
    push_down(now,lalal);
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    up1(now,s1,x);up1(now,s2,x);
    update(now,lalal);
}
queue<int> q;
void up (int l,int r,int x)//这一段区间都变为x
{
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
    l=l-L[lp]+1;r=r-L[lp]+1;
        KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
        int lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<l||A[u].id>r)||A[u].x>=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        bool tf=false;int ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(lp,1,ooo);
        return ;
    }
    for (int u=belong[l]+1;u<belong[r];u++) up1(u,1,x);
    /*更新l这个块*/
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
        int lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<ll||A[u].id>rr)||A[u].x>=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        bool tf=false;int ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(lp,1,ooo);
    /*更新l这个块*/
    /*更新r这个块*/
    ll=1,rr=r-L[rp]+1;
    KO=0;rebuild1(rp,1);//得到了一个有序的叶子信息
        lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<ll||A[u].id>rr)||A[u].x>=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        tf=false;ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(rp,1,ooo);
    /*更新r这个块*/
}
void down1 (int now,int lalal,int x)//将这一个块大于x都变为x
{
    if (tr[now][lalal].minn>=x)//这一段都要变为x了
    {
        Same(now,lalal,x);
        return ;
    }
    if (tr[now][lalal].maxx<=x)//最小都GG
        return ;
    if (tr[now][lalal].l==tr[now][lalal].r) return ;
    push_down(now,lalal);
    int s1=tr[now][lalal].s1,s2=tr[now][lalal].s2;
    down1(now,s1,x);
    down1(now,s2,x);
    update(now,lalal);
}
void down (int l,int r,int x)
{
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
        l=l-L[lp]+1;r=r-L[lp]+1;
        KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
        int lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<l||A[u].id>r)||A[u].x<=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        bool tf=false;int ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(lp,1,ooo);
        return ;
    }
    for (int u=belong[l]+1;u<belong[r];u++) down1(u,1,x);
    /*更新l这个块*/
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    KO=0;rebuild1(lp,1);//得到了一个有序的叶子信息
        int lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<ll||A[u].id>rr)||A[u].x<=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        bool tf=false;int ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(lp,1,ooo);
    /*更新l这个块*/
    /*更新r这个块*/
    ll=1,rr=r-L[rp]+1;
    KO=0;rebuild1(rp,1);//得到了一个有序的叶子信息
        lalal=0;
        for (int u=1;u<=KO;u++)
            if ((A[u].id<ll||A[u].id>rr)||A[u].x<=x)
                B[++lalal]=A[u];//可行
            else    q.push(A[u].id);
        tf=false;ooo=0;
        for (int u=1;u<=lalal;u++)//吧每一个数都放进去
        {
            if (tf==false&&x<=B[u].x)//找到位置了
            {
                while (!q.empty())
                {
                    a[++ooo].id=q.front();
                    a[ooo].x=x;
                    q.pop();
                }
                tf=true;
            }
            a[++ooo]=B[u];
        }
        if (tf==false)
        {
            while (!q.empty())
            {
                a[++ooo].id=q.front();
                a[ooo].x=x;
                q.pop();
            }
        }
        num=0;bt(rp,1,ooo);
    /*更新r这个块*/
}
LL get_sum (int l,int r)//得到这两个地方的和
{
    LL ans=0;
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
        int Num=R[lp]-L[lp]+1;
        rebuild(lp,1);
        l=l-L[lp]+1;r=r-L[lp]+1;
        for (int u=l;u<=r;u++)  ans=ans+p[u];
        return ans;
    }
    for (int u=belong[l]+1;u<belong[r];u++) ans=ans+tr[u][1].sum;
    /*更新l这个块*/
    rebuild(lp,1);
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    for (int u=ll;u<=rr;u++)    ans=ans+p[u];
    /*更新l这个块*/
    /*更新r这个块*/
    rebuild(rp,1);
    ll=1,rr=r-L[rp]+1;
    for (int u=ll;u<=rr;u++)
        ans=ans+p[u];
    /*更新r这个块*/
    return ans;
}
int get_max (int l,int r)//得到这两个地方的和
{
    int ans=-MAX;
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
        int Num=R[lp]-L[lp]+1;
        rebuild(lp,1);
        l=l-L[lp]+1;r=r-L[lp]+1;
        for (int u=l;u<=r;u++)
            ans=max(ans,p[u]);
        return ans;
    }
    for (int u=belong[l]+1;u<belong[r];u++) ans=max(ans,tr[u][1].maxx);
    /*更新l这个块*/
    rebuild(lp,1);
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    for (int u=ll;u<=rr;u++)    ans=max(ans,p[u]);
    /*更新l这个块*/
    /*更新r这个块*/
    rebuild(rp,1);
    ll=1,rr=r-L[rp]+1;
    for (int u=ll;u<=rr;u++)    ans=max(ans,p[u]);
    /*更新r这个块*/
    return ans;
}
int get_min (int l,int r)//得到这两个地方的和
{
    int ans=MAX;
    int lp=belong[l],rp=belong[r];
    if (lp==rp)
    {
        int Num=R[lp]-L[lp]+1;
        rebuild(lp,1);
        l=l-L[lp]+1;r=r-L[lp]+1;
        for (int u=l;u<=r;u++)  ans=min(ans,p[u]);
        return ans;
    }
    for (int u=belong[l]+1;u<belong[r];u++) ans=min(ans,tr[u][1].minn);
    /*更新l这个块*/
    rebuild(lp,1);
    int ll=l-L[lp]+1,rr=R[lp]-L[lp]+1;
    for (int u=ll;u<=rr;u++)    ans=min(ans,p[u]);
    /*更新l这个块*/
    /*更新r这个块*/
    rebuild(rp,1);
    ll=1,rr=r-L[rp]+1;
    for (int u=ll;u<=rr;u++)    ans=min(ans,p[u]);
    /*更新r这个块*/
    return ans;
}

void solve()
{
    int m=read();
    while (m--)
    {
        int op=read();
        int x,y,z;
        switch (op)
        {
            case 1:x=read();y=read();z=read();ADD(x,y,z);break;
            case 2:x=read();y=read();z=read();up(x,y,z);break;
            case 3:x=read();y=read();z=read();down(x,y,z);break;
            case 4:x=read();y=read();printf("%lld\n",get_sum(x,y));break;
            case 5:x=read();y=read();printf("%d\n",get_max(x,y));break;
            case 6:x=read();y=read();printf("%d\n",get_min(x,y));break;
        }
    }
}

struct re{
	int l,r,c,p;
	re(){};
	re(int l,int r,int c,int p):l(l),r(r),c(c),p(p){};
	bool operator < (const re& b){
		return p<b.p;
	};
};

vector<re> arr;
typedef unsigned long long ull;

int main()
{
	n = read();
	k = read();
	m = read();
	nn = sqrt(n);
	arr.resize(m);

	for (int i=0; i<m; i++){
	 int l,r,c,p;
	 l = read();
	 r = read();
	 c = read();
	 p = read();
	 // cout<<"l = "<<l<<endl;
	 arr[i].l = l;
	 arr[i].r = r;
	 arr[i].c = c;
	 arr[i].p = p;
	}
	sort(arr.begin(),arr.end());
	prepare();

	ull ans = 0;
	for (int i=0; i<arr.size(); i++){
	 int l,r,c,p;
	 l = arr[i].l;
	 r = arr[i].r;
	 c = arr[i].c;
	 p = arr[i].p;

	 ull tp = c*(r-l+1);
	 // ull sum0 = smt::getsum(1,1,n,l,r);
	 ull sum0 = get_sum(l,r);

	 // smt::add(1,1,n,l,r,c);
	 ADD(l,r,c);
	 // smt::changemax(1,1,n,l,r,k);
	 down(l,r,k);
	 // ull sum2 = smt::getsum(1,1,n,l,r);
	 ull sum2 = get_sum(l,r);

	 tp = (sum2-sum0)*p;
	 ans += tp;
	}

	printf("%lld\n",ans);
    return 0;
}
