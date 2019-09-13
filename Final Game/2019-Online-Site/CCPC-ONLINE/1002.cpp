#include<bits/stdc++.h>
using namespace std;

int ans,Case,n,m,a[100007],T[1000007];

void Modify(int l,int r,int id,int p,int dea){
    if (l==r){
        T[id]=dea;
        return;
    }
    int mid=(l+r)>>1,lid=id<<1,rid=lid+1;
    if (p<=mid) Modify(l,mid,lid,p,dea);
    else Modify(mid+1,r,rid,p,dea);
    T[id]=max(T[lid],T[rid]);
}

int Query(int l,int r,int id,int p,int s){
    if (s>r) return n+1;
    if (l==r){
        if (T[id]>=p) return l;
        return n+1;
    }
    int mid=(l+r)>>1,lid=id<<1,rid=lid+1,ans=n+1;
    if (s<=mid&&T[lid]>=p) ans=min(ans,Query(l,mid,lid,p,s));
    if (ans!=n+1) return ans;
    if (s<=r&&T[rid]>=p) ans=min(ans,Query(mid+1,r,rid,p,s));
    return ans;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> Case;
    while (Case--){
        ans=0;
		cin >> n >> m;
        for (int i=1;i<=n;++i){
			cin >> a[i];
            Modify(1,n+1,1,a[i],i-1);
        }
        int opt,Pos,R,K;
        for (int i=1;i<=m;++i){
			cin >> opt;
            if (opt==1){
				cin >> Pos;
            	Pos^=ans;
                Modify(1,n+1,1,a[Pos],n+1);
            }
            else {
				cin >> R >> K;
                R^=ans,K^=ans;
                ans=Query(1,n+1,1,R,K);
				cout << ans << '\n';
            }
        }
        for (int i=1;i<=4*n;++i) T[i]=0;
    }
}
