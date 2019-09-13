#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define int long long

struct Info{
    ll s,Num;
}tr[800007];

int ans,Q,n,nn,m,w[200007],q[200007];

void Modify(int l,int r,int id,int k){
    if (l==r){
        tr[id].s+=q[k];
        ++tr[id].Num;
        return;
    }
    int mid=(l+r)>>1,lid=id<<1,rid=lid+1;
    if (k<=mid) Modify(l,mid,lid,k);
    else Modify(mid+1,r,rid,k);
    tr[id].s=tr[lid].s+tr[rid].s;
    tr[id].Num=tr[lid].Num+tr[rid].Num;
}

ll Querry(int l,int r,int id,ll k){
    if (k==tr[id].Num) return tr[id].s;
    if (l==r)
      return q[l]*k;
    int mid=(l+r)>>1,lid=id<<1,rid=lid+1;
    if (tr[lid].Num>=k)
     return Querry(l,mid,lid,k);
    else
     return tr[lid].s+Querry(mid+1,r,rid,k-tr[lid].Num);
}

bool cmp(int x,int y){
    return x>y;
}

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
  for (cin>>Q;Q;--Q){
      unordered_map<int,int>Hash;
      ll Total=0;
      memset(tr,0,sizeof tr);
      memset(w,0,sizeof w);
      memset(q,0,sizeof q);
      cin>>n>>m;
      for (int i=1;i<=n;++i){
		  cin>>w[i],q[i]=w[i];
	  }

	sort(q+1,q+n+1,cmp);
    nn=unique(q+1,q+n+1)-q-1;
    for (int i=1;i<=nn;++i)
     Hash[q[i]]=i;
    cout << "0 ";
    Total=w[1];
    ans=0;
    for (int i=2;i<=n;++i){
        Total+=w[i];
        Modify(1,nn,1,Hash[w[i-1]]);
        int l=0,r=i-1,mid;
        if (Total>m){
         while (r-l>7){
            mid=(l+r)>>1;
            ll S=Querry(1,nn,1,mid);
            if (Total-S<=m) r=mid;
            else l=mid+1;
            if (Total-S==m) l=r=mid;
          }
          for (int j=l;j<=r;++j)
           if (Total-Querry(1,nn,1,j)<=m){
               ans=j;
			   break;
           }
        }
        cout << ans << ' ';
    }
	cout << '\n';
  }
  return 0;
}
