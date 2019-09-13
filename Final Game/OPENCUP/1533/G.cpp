// fyt
#include<bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 112345;

struct node{
	int l,r;
	int sum,add;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
}tree[maxn*4];

int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		sum(p) = 0;
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p) = sum(p*2)+sum(p*2+1);
}


void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		sum(p) += d*(r(p)-l(p)+1);
		return ;
	}
	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
}

int ask(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return sum(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = 0;
	if(l<=mid)val += ask(p*2,l,r);
	if(r > mid)val += ask(p*2+1,l,r);
	return val;
}

int v[maxn];
int pre[maxn];
int suf[maxn];

int main () {
	// ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
	for (int i=1; i<=n; i++){
		cin >> v[i];
	}

    build(1,1,1e5+1);
	int temp = 0;
    for (int i=1; i<=n; i++) {
        temp += ask(1,v[i]+1,1e5+1);
		pre[i] = temp;
        change(1,v[i],v[i],1);
    }

	memset(tree,0,sizeof(tree));
	build(1,1,1e5+1);
	temp = 0;
	for (int i=n; i>=1; i--) {
        temp += ask(1,v[i]+1,1e5+1);
		suf[i] = temp;
        change(1,v[i],v[i],1);
    }

	long long mn = 1e18;
	for (int i=1; i<=n-1; i++){
		cout<<"pre[i] = "<<pre[i]<<endl;
		cout<<"suf[i] = "<<suf[i]<<endl;
		cout<<"mn = "<<mn<<endl;
		mn = min(mn,(long long)pre[i]+suf[i+1]);
	}
	cout << mn << endl;
}
