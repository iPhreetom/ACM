#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int ,int >pii;
#define clr(a,x) memset(a,x,sizeof a)
const int MAXN=512345;
const int MAXE=1012345;
struct Edge{
    int v,n;
    Edge(){}
    Edge(int v,int n):v(v),n(n){}
}E[MAXE];
int H[MAXN],cntE;
int dep[MAXN],pre[MAXN],top[MAXN],son[MAXN],siz[MAXN],tree_idx;
int in[MAXN],ou[MAXN],dfs_idx;
set<pii>s;
map<int,set<pii>> col;
set<pii>::iterator it,it1;
int c[MAXN],T[MAXN],setv[MAXN*10],n,q;
void addedge(int u,int v){E[cntE]=Edge(v,H[u]);H[u]=cntE++;}
void dfs(int u){
    in[u]=++dfs_idx;
    siz[u]=1;
    son[u]=0;
    for(int i=H[u];~i;i=E[i].n){
        int v=E[i].v;
        if(v==pre[u])continue;
        pre[v]=u;
        dep[v]=dep[u]+1;
        dfs(v);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v])son[u]=v;
    }
    ou[u]=dfs_idx;
}
void rebuild(int u,int top_element){
    top[u]=top_element;
    if(son[u])rebuild(son[u],top_element);
    for(int i=H[u];~i;i=E[i].n)if(E[i].v!=pre[u]&&E[i].v!=son[u])rebuild(E[i].v,E[i].v);
}
int lca(int x,int y){
    while(top[x]!=top[y])dep[top[x]]>dep[top[y]]?x=pre[top[x]]:y=pre[top[y]];
    return dep[x]<dep[y]?x:y;
}
void build(int o,int l,int r){
    setv[o]=0;
    if(l==r)setv[o]=c[in[l]];
    else {
        int m=l+r>>1;
        build(o<<1,l,m);
        build(o<<1|1,m+1,r);
    }
}
void down(int o){if(setv[o])setv[o<<1]=setv[o<<1|1]=setv[o],setv[o]=0;}
void update(int L,int R,int v,int o,int l,int r){
    if(L<=l&&r<=R)setv[o]=v;
    else {
        down(o);
        int m=l+r>>1;
        if(L<=m)update(L,R,v,o<<1,l,m);
        if(m<R)update(L,R,v,o<<1|1,m+1,r);
    }
}
int query(int x,int o,int l,int r){
    for(int m=l+r>>1;l<r;x<=m?(o=o<<1,r=m):(o=o<<1|1,l=m+1),m=l+r>>1)down(o);
    return setv[o];
}
void add(int x,int v){for(int i=x;i<=n;i+=i&-i)T[i]+=v;}
int sum(int x,int ans=0){
    for(int i=x;i>=1;i-=i&-i)ans+=T[i];
    return ans;
}
int get(int x,int x1=0,int x2=0){
    if(it!=col[c[x]].begin())x1=lca((--(it1=it))->second,x);
    if((++(it1=it))!=col[c[x]].end())x2=lca(it1->second,x);
    if(dep[x1]>dep[x2])return x1;
    return x2;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int op,x,y;
    cin >> n;
    cntE=dfs_idx=tree_idx=0;
    s.clear();
    for(int i=1;i<=n;++i)H[i]=-1,col[i].clear(),T[i]=0;
    for(int i=1;i<n;i++) {
		cin >> x >> y;
		addedge(x,y),addedge(y,x);
	}
    dfs(dep[1]=1),rebuild(1,1);
    for(int i=1;i<=n;++i){
        cin >> c[i];
        col[c[i]].insert(make_pair(in[i],i));
        s.insert(make_pair(in[i],i));
    }
    build(1,1,n);
    for(int i=1,pre=0;i<=n;++i,pre=0){
        for(it=col[i].begin();it!=col[i].end();++it){
            add(it->first,1);
            if(pre)add(in[lca(pre,it->second)],-1);
            pre=it->second;
        }
    }
	cin >> q;
    for(int i=1;i<=q;++i){
        cin >> op >> x;
        pii tmp(in[x],x);
        if(op==1){
            cin >> y;
            while(1){
                it=s.lower_bound(tmp);
                if(it==s.end()||it->first>ou[x])break;
                int u=it->second;
                it=col[c[u]].find(*it);
                int x1=get(u);
                if(x1)add(in[x1],1);
                add(in[u],-1);
                pii tmp1=*it;
                s.erase(tmp1);
                col[c[u]].erase(tmp1);
                c[u]=y;
            }
            c[x]=y;
            s.insert(tmp);
            col[y].insert(tmp);
            it=col[y].find(tmp);
            int x1=get(x);
            if(x1)add(in[x1],-1);
            add(in[x],1);
            update(in[x],ou[x],y,1,1,n);
        }else{
            int ans=sum(ou[x])-sum(in[x]-1);
            it=s.lower_bound(tmp);
            if(it==s.end())++ans;
            else if(it->second!=x){
                int color=query(in[x],1,1,n);
                it=col[color].lower_bound(tmp);
                if(it==col[color].end()||it->first>ou[x])++ans;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
