// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxn = 112345;

struct node{
	int l,r;
	int maxx,addm,minn;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define maxx(x) tree[x].maxx
	#define minn(x) tree[x].minn
	#define add(x) tree[x].add
}tree[maxn*4];

int a[maxn];

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		maxx(p) = a[l];
		minn(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	maxx(p) = max(maxx(p*2),maxx(p*2+1));
	minn(p) = min(minn(p*2),minn(p*2+1));
}


int askmx(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return maxx(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = -1e17;
	if(l<=mid)val = max(val,askmx(p*2,l,r));
	if(r > mid)val = max(val,askmx(p*2+1,l,r));
	return val;
}

int askmn(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return minn(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = 1e17;
	if(l<=mid)val = min(val,askmn(p*2,l,r));
	if(r > mid)val = min(val,askmn(p*2+1,l,r));
	return val;
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,s,lst;
	cin>>n>>s>>lst;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	build(1,1,n);
	int l=1;
	int r=lst;
	bool ok = 1;
	int sum = 0;

	for (int i=lst; i<=n; i++){
		r = i;
		int mx = askmx(1,l,r);
		int mn = askmn(1,l,r);
		if(mx - mn <= s){

		}
	}

	return 0;
}
