// ZOJ 1610
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

const int maxn = 8005;

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
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p) = sum(p*2)+sum(p*2+1);
}

void spread(int p){
	if(add(p)){
		sum(p*2) = add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1) = add(p)*(r(p*2+1)-l(2*p+1)+1);


		add(2*p) = add(p);
		add(2*p+1) = add(p);

		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		sum(p) = d*(r(p)-l(p)+1);
		add(p) = d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return sum(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 0;

	if(l<=mid)val += ask(p*2,l,r);
	if(r > mid)val += ask(p*2+1,l,r);

	return val;
}

int ans[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n){
		memset(tree,0,sizeof(tree));
		memset(a,-1,sizeof(a));
		memset(ans,0,sizeof(ans));
		vector<int> v;

		build(1,1,maxn);
		for (int i=0; i<n; i++){
			int l,r,c;
			cin>>l>>r>>c;
			change(1,l+1,r,c+1);
		}


		set<int> s;
		for (int i=1; i<=8001; i++){
			int tp = ask(1,i,i);
			// cout<<tp<<' ';
			if(tp == -1)continue;
			if(i == 1){
				ans[tp]++;
			}
			else{
				if(tp != ask(1,i-1,i-1)){
					ans[tp]++;
				}
				else{
					if(i == 8001){
						ans[tp]++;
					}
				}
			}
			s.insert(tp);
		}
		// cout<<endl;

		for(auto i:s){
			cout<<i-1<<' '<<ans[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}
