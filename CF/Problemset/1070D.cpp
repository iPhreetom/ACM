#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 2e5+5;

struct node{
	int vsum,nsum;
	int vadd,nadd;
	int l,r;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define vadd(x) tree[x].vadd
	#define nadd(x) tree[x].nadd
	#define vsum(x) tree[x].vsum
	#define nsum(x) tree[x].nsum
}tree[4*maxn+5];

int a[maxn];

void build(int p,int l,int r){
	l(p) = l;r(p) = r;
	vadd(p) = 0;nadd(p) = 0;

	if(l == r){
		vsum(p) = a[l]*l;
		nsum(p) = a[l];
		return ;
	}

	int mid = l+(r-l)/2;
	build(p*2,l,mid);
	if(r > mid)build(p*2+1,mid+1,r);
	vsum(p) = vsum(p*2)+vsum(p*2+1);
	nsum(p) = nsum(p*2)+nsum(p*2+1);
}

void spread(int p){
	if(vadd(p)){
		// vsum(p) += (r(p)-l(p)+1)*
	}
}

void change(int p,int l,int r,int d){

}

// void

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,m;

	return 0;
}
