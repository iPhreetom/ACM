// POJ - 3264

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define endl '\n'
using namespace std;

const int maxn = 51234;

struct node{
	int l,r;
	int add;//区间求和
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	// #define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define maxx(x) tree[x].mx
	#define minn(x) tree[x].mn
}tree[maxn*4];

int a[maxn];
int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		minn(p) = a[l];
		maxx(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	minn(p) = min(minn(p*2),minn(p*2+1));
	maxx(p) = max(maxx(p*2),maxx(p*2+1));
}

void spread(int p){
	if(add(p)){
		minn(p*2) += add(p);
		minn(p*2+1) += add(p);
		maxx(p*2) += add(p);
		maxx(p*2+1) += add(p);

		add(2*p) += add(p);
		add(2*p+1) += add(p);

		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		minn(p) += d;
		maxx(p) += d;
		add(p) += d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	minn(p) = min(minn(2*p),minn(2*p+1));
	maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int askmax(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		// return sum(p);
		// return minn(p);
		return maxx(p);
	}

	// spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 0;

	if(l<=mid)val = max(val,askmax(p*2,l,r));
	if(r > mid)val = max(val,askmax(p*2+1,l,r));

	return val;
}

int askmin(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		// return sum(p);
		return minn(p);
		// return maxx(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 1e9;

	if(l<=mid)val = min(askmin(p*2,l,r),val);
	if(r > mid)val = min(askmin(p*2+1,l,r),val);

	return val;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;

	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	build(1,1,n);
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<abs(askmax(1,l,r)-askmin(1,l,r))<<endl;
	}
	return 0;
}
