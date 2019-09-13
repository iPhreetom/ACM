#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
#define ll long long

const ll Mod=1<<30;
ll ql,qr,K;
ll T,n,m,tr[1000007];
unsigned int x,y,z,w;
unsigned int f[3];

void Modify(int l,int r,int id){
	 if (tr[id]>K) return;
     int mid=(l+r)>>1,lid=id<<1,rid=lid+1;
	 if (l>=ql&&r<=qr){
	 	tr[id]=max(tr[id],K);
	 	tr[lid]=max(tr[lid],tr[id]);
	 	tr[rid]=max(tr[rid],tr[id]);
	 	return;
	 }
	 tr[lid]=max(tr[lid],tr[id]);
	 tr[rid]=max(tr[rid],tr[id]);
	 if (ql<=mid&&qr>=l)
	  Modify(l,mid,lid);
	 if (ql<=r&&qr>mid)
	  Modify(mid+1,r,rid);
}

unsigned int RNG(){
	x=x^(x<<11);
	x=x^(x>>4);
	x=x^(x<<5);
	x=x^(x>>14);
	w=x^(y^z);
	x=y;
	y=z;
	z=w;
	return z;
}

ll Q(int l,int r,int id,int p){
	if (l==r) return tr[id];
	int mid=(l+r)>>1,lid=id<<1,rid=lid+1;
	tr[lid]=max(tr[lid],tr[id]);
	tr[rid]=max(tr[rid],tr[id]);
	if (p<=mid) return Q(l,mid,lid,p);
	else return Q(mid+1,r,rid,p);
}

int main(){
  ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

  for (cin>>T;T;--T){
  	memset(tr,0,sizeof tr);
  	cin>>n>>m>>x>>y>>z;
  	for (int i=1;i<=m;++i){
  		f[0]=RNG();f[1]=RNG();f[2]=RNG();
  		ql=min(f[0]%n+1,f[1]%n+1);
  		qr=max(f[0]%n+1,f[1]%n+1);
  		K=f[2]%Mod;
  		Modify(1,n,1);
  	}
  	ll ans=0;
  	for (ll i=1;i<=n;++i)
	  ans^=(i*Q(1,n,1,i));
    cout<<ans<<endl;
  }
  return 0;
}
