#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
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

int a[maxn];
int y[maxn];
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
		sum(p*2)+= add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1) += add(p)*(r(p*2+1)-l(2*p+1)+1);
		add(2*p) += add(p);
		add(2*p+1) += add(p);
		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		sum(p) += d*(r(p)-l(p)+1);
		add(p) += d;
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
	int n,q;
	cin>>n>>q;
	for (int i=1; i<=n; i++){
	    cin>>a[i];
		y[i] = a[i];
	}
	for (int i=1; i<=n; i++){
	    a[i] += a[i-1];
	}
	build(1,1,n);
	for (int i=1; i<=q; i++){
	    int a,b,c;
		cin>>a>>b>>c;
		if(a == 1){
			if(b == 1){
				cout<<ask(1,b,c)<<endl;
			}
			else{
				cout<<ask(1,b,c)-ask(1,b-1,b-1)*(c-b+1)<<endl;
			}
		}
		else{
			// cout<<c-y[b]<<endl;
			change(1,b,n,c-y[b]);
			y[b] = c;
		}
	}
	return 0;
}
