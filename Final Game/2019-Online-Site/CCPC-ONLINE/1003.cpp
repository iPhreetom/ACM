#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define N 100005
using namespace std;

//输入输出挂
namespace fastIO
{
#define BUF_SIZE 100000
#define OUT_SIZE 100000
#define ll long long
    //fread->read
    bool IOerror = 0;
    inline char nc()
    {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend)
        {
            p1 = buf; pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1) { IOerror = 1; return -1; }
            //{printf("IO error!\n"); system("pause"); for (;;); exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
    inline void read(int &x)
    {
        bool sign = 0; char ch = nc(); x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror) return;
        if (ch == '-') sign = 1, ch = nc();
        for (; ch >= '0'&&ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
        if (sign) x = -x;
    }
    inline void read(ll &x)
    {
        bool sign = 0; char ch = nc(); x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror) return;
        if (ch == '-') sign = 1, ch = nc();
        for (; ch >= '0'&&ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
        if (sign) x = -x;
    }
    inline void read(double &x)
    {
        bool sign = 0; char ch = nc(); x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror) return;
        if (ch == '-') sign = 1, ch = nc();
        for (; ch >= '0'&&ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
        if (ch == '.')
        {
            double tmp = 1; ch = nc();
            for (; ch >= '0'&&ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
        }
        if (sign) x = -x;
    }
    inline void read(char *s)
    {
        char ch = nc();
        for (; blank(ch); ch = nc());
        if (IOerror) return;
        for (; !blank(ch) && !IOerror; ch = nc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = nc(); blank(c); c = nc());
        if (IOerror) { c = -1; return; }
    }
    //fwrite->write
    struct Ostream_fwrite
    {
        char *buf, *p1, *pend;
        Ostream_fwrite() { buf = new char[BUF_SIZE]; p1 = buf; pend = buf + BUF_SIZE; }
        void out(char ch)
        {
            if (p1 == pend) { fwrite(buf, 1, BUF_SIZE, stdout); p1 = buf; }
            *p1++ = ch;
        }
        void print(int x)
        {
            static char s[15], *s1; s1 = s;
            if (!x) *s1++ = '0'; if (x < 0) out('-'), x = -x;
            while (x) *s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s) out(*s1);
        }
        void println(int x)
        {
            static char s[15], *s1; s1 = s;
            if (!x) *s1++ = '0'; if (x < 0) out('-'), x = -x;
            while (x) *s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s) out(*s1); out('\n');
        }
        void print(ll x)
        {
            static char s[25], *s1; s1 = s;
            if (!x) *s1++ = '0'; if (x < 0) out('-'), x = -x;
            while (x) *s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s) out(*s1);
        }
        void println(ll x)
        {
            static char s[25], *s1; s1 = s;
            if (!x) *s1++ = '0'; if (x < 0) out('-'), x = -x;
            while (x) *s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s) out(*s1); out('\n');
        }
        void print(double x, int y)
        {
            static ll mul[] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL };
            if (x < -1e-12) out('-'), x = -x; x *= mul[y];
            ll x1 = (ll)floor(x); if (x - floor(x) >= 0.5) ++x1;
            ll x2 = x1 / mul[y], x3 = x1 - x2 * mul[y]; print(x2);
            if (y > 0) { out('.'); for (size_t i = 1; i < y&&x3*mul[i] < mul[y]; out('0'), ++i); print(x3); }
        }
        void println(double x, int y) { print(x, y); out('\n'); }
        void print(char *s) { while (*s) out(*s++); }
        void println(char *s) { while (*s) out(*s++); out('\n'); }
        void flush() { if (p1 != buf) { fwrite(buf, 1, p1 - buf, stdout); p1 = buf; } }
        ~Ostream_fwrite() { flush(); }
    } Ostream;
    inline void print(int x) { Ostream.print(x); }
    inline void println(int x) { Ostream.println(x); }
    inline void print(char x) { Ostream.out(x); }
    inline void println(char x) { Ostream.out(x); Ostream.out('\n'); }
    inline void print(ll x) { Ostream.print(x); }
    inline void println(ll x) { Ostream.println(x); }
    inline void print(double x, int y) { Ostream.print(x, y); }
    inline void println(double x, int y) { Ostream.println(x, y); }
    inline void print(char *s) { Ostream.print(s); }
    inline void println(char *s) { Ostream.println(s); }
    inline void println() { Ostream.out('\n'); }
    inline void flush() { Ostream.flush(); }
#undef OUT_SIZE
#undef BUF_SIZE
};

//使用
using namespace fastIO;

int T,Q;
int st[N][18];
char s[N];
int Rank[N],y[N],tmp[N];
int c[N],SA[N],n,m,Height[N];
void Sort(){
    for(int i=1;i<=m;i++) c[i] = 0;
    for(int i=1;i<=n;i++) c[Rank[i]]++;
    for(int i=2;i<=m;i++) c[i] += c[i-1];
    for(int i=n;i>=1;i--) SA[c[Rank[y[i]]]--] = y[i];
}
void get_SA(){
    for(int i=1;i<=n;i++) Rank[i] = s[i] , y[i] = i;
    Sort();
    for(int k=1;k<=n;k<<=1){
        int cnt = 0;
        for(int i=n-k+1;i<=n;i++) y[++cnt] = i;
        for(int i=1;i<=n;i++) if(SA[i]>k) y[++cnt] = SA[i] - k;
        Sort(); swap(Rank,tmp); int num = 1; Rank[SA[1]] = 1;
        for(int i=2;i<=n;i++){
            if(tmp[SA[i]] == tmp[SA[i-1]] && tmp[SA[i]+k] == tmp[SA[i-1]+k])
                Rank[SA[i]] = num;
            else Rank[SA[i]] = ++num;
        } m = num;
    }
}
void get_Hi(){
    int k = 0;
    for(int i=1;i<=n;i++){
        if(Rank[i]==1) continue;
        int j = SA[Rank[i]-1]; if(k) k--;
        while(i+k<=n && j+k<=n && s[i+k]==s[j+k]) k++;
        Height[Rank[i]] = k;
        st[Rank[i]][1]=k;
        st[Rank[i]][0]=n;
    }
    for (int i=2;i<=17;++i)
     for (int j=2;j<=n;++j)
       if (j-(1<<i)+1>0)
           st[j][i]=min(st[j][i-1],st[j-(1<<(i-1))][i-1]);
}

int Get_Min(int l,int r){
    int p=log2(r-l+1);
    return min(st[r][p],st[l+(1<<p)-1][p]);
}

struct Info{
    int hl,hr;
    int L,R,K,id;
}Que[N],q1[N],q2[N];

int sum[N],ans[N];

inline void Solve(int ql,int qr,int l,int r){
    if (l==r){
        for (int i=ql;i<=qr;++i)
        if (Que[i].K==1){
            if (Rank[l]<Que[i].hl||Rank[l]>Que[i].hr) continue;
            ans[Que[i].id]=l;
        }
        return;
    }
    for (int i=1;i<=n;++i) sum[i]=0;
    int mid=(l+r)>>1,cnt1=0,cnt2=0;
    for (int i=l;i<=mid;++i)
        sum[Rank[i]]++;
    for (int i=1;i<=n;++i) sum[i]+=sum[i-1];
    for (int i=ql;i<=qr;++i){
        int tot=sum[Que[i].hr]-sum[Que[i].hl-1];
        if (tot<Que[i].K) {
            Que[i].K-=tot;
            q2[++cnt2]=Que[i];
        }
        else {
            q1[++cnt1]=Que[i];
        }
    }
    for (int i=1;i<=cnt1;++i)
     Que[ql+i-1]=q1[i];
    for (int i=1;i<=cnt2;++i)
     Que[ql+cnt1-1+i]=q2[i];

     Solve(ql,ql+cnt1-1,l,mid);
     Solve(ql+cnt1,qr,mid+1,r);
}

int main(){
    memset(ans,-1,sizeof ans);
    read(T);
    while (T--){
       read(n),read(Q);
       read(s+1);
       m = 127; get_SA();get_Hi();
       for (int i=1;i<=Q;++i){
           read(Que[i].L),read(Que[i].R),read(Que[i].K);
        Que[i].id=i;
        int l=1,r=Rank[Que[i].L],mid,tot=Que[i].R-Que[i].L+1;
        while (l<r){
            mid=(l+r)>>1;
            if (Get_Min(mid,Rank[Que[i].L])>=tot)
             r=mid;
            else l=mid+1;
        }
        Que[i].hl=l;
        l=Rank[Que[i].L],r=n;
        while (l<r-1){
            mid=(l+r)>>1;
            if (Get_Min(Rank[Que[i].L],mid)>=tot)
             l=mid;
            else r=mid-1;
        }
        Que[i].hr=l;
        if (l<n&&Get_Min(Rank[Que[i].L],l+1)>=tot)
         ++Que[i].hr;
       }
       Solve(1,Q,1,n);
       for (int i=1;i<=Q;++i)
        println(ans[i]),ans[i]=-1;
    }
    return 0;
}
