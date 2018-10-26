
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
#define int long long
#define double long double
using namespace std;

const int maxn = 21234;

struct node{
	int l,r;
	int sum,add;//区间求和
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
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
		sum(p) = a[l];
		// minn(p) = a[l];
		// maxx(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p) = sum(p*2)+sum(p*2+1);
	// minn(p) = min(minn(p*2),minn(p*2+1));
	// maxx(p) = max(maxx(p*2),maxx(p*2+1));
}

void spread(int p){
	if(add(p)){
		sum(p*2) = add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1) = add(p)*(r(p*2+1)-l(2*p+1)+1);
		// minn(p*2) += add(p);
		// minn(p*2+1) += add(p);
		// maxx(p*2) += add(p);
		// maxx(p*2+1) += add(p);


		add(2*p) = add(p);
		add(2*p+1) = add(p);

		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		sum(p) = d*(r(p)-l(p)+1);
		// minn(p) += d;
		// maxx(p) += d;
		add(p) = d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
	// minn(p) = min(minn(2*p),minn(2*p+1));
	// maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return sum(p);
		// return minn(p);
		// return maxx(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 0;

	if(l<=mid)val += ask(p*2,l,r);
	if(r > mid)val += ask(p*2+1,l,r);

	return val;
}

int larr[11234];
int rarr[11234];
bool color[21234];
int h[21234];

signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tgt;
	cin>>tgt;
	for(int c=1; c<=tgt; c++){
		int n;
		cin>>n;
		memset(tree,0,sizeof(tree));
		memset(color,0,sizeof(color));
		memset(a,0,sizeof(a));
		memset(h,0,sizeof(h));


		int index = 1;
		int len = 1;
		for (int i=1; i<=n; i++){
			cin>>larr[i]>>rarr[i];
			h[len++] = larr[i];
			h[len++] = rarr[i];
		}

		sort(h+1,h+len);
		int sz = unique(h+1,h+len)-h-1;

		for (int i=1; i<=n; i++){
			larr[i] = lower_bound(h+1,h+sz+1,larr[i])-h;
			rarr[i] = lower_bound(h+1,h+sz+1,rarr[i])-h;
			int mx = max(larr[i],rarr[i]);
			// cout<<"mx = "<<mx<<endl;
		}

		int maxn = sz;
		build(1,1,maxn);
		index = 1;

		for (int i=1; i<=n; i++){
			change(1,larr[i],rarr[i],++index);
		}


		for (int i=1; i<=maxn; i++){
			color[ask(1,i,i)] = 1;
		}

		int ans = 0;
		for (int i=1; i<=index; i++){
			if(color[i])ans++;
		}

		cout<<ans<<endl;
	}
	return 0;
}
