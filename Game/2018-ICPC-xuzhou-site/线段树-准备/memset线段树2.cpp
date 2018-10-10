// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 112345;

struct node{
	int l,r;
	int sum,add;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[maxn*4];

// int a[maxn];
int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		sum(p) = 1;
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


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for (int j=0; j<t; j++){
		memset(tree,0,sizeof(tree));
		int n,q;
		cin>>n>>q;
		build(1,1,n);
		for (int i=0; i<q; i++){
		    int l,r,v;
			cin>>l>>r>>v;
			change(1,l,r,v);
		}
		cout<<"Case "<<j+1<<": The total value of the hook is "<<ask(1,1,n)<<"."<<endl;
	}

	return 0;
}
