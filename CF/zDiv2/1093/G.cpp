#include<bits/stdc++.h>
using namespace std;

int a[212345][6];
int b[212345][32];
const int maxn = 212345;


struct node{
	int l,r;
	int sum,add;//区间求和
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define add(x) tree[x].add
	#define maxx(x) tree[x].mx
	#define minn(x) tree[x].mn
}tree[maxn*2];

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		sum(p) = a[l];
		minn(p) = a[l];
		maxx(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p) = sum(p*2)+sum(p*2+1);
	minn(p) = min(minn(p*2),minn(p*2+1));
	maxx(p) = max(maxx(p*2),maxx(p*2+1));
}

void spread(int p){
	if(add(p)){
		sum(p*2) += add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1) += add(p)*(r(p*2+1)-l(2*p+1)+1);
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
		sum(p) += d*(r(p)-l(p)+1);
		minn(p) += d;
		maxx(p) += d;
		add(p) += d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
	minn(p) = min(minn(2*p),minn(2*p+1));
	maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return sum(p);
		return minn(p);
		return maxx(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 0;

	if(l<=mid)val += ask(p*2,l,r);
	if(r > mid)val += ask(p*2+1,l,r);

	return val;
}

void make_tree() {
	for (int i=1; i<=n; i++){
		for (int j=0; j<32; j++){
			int val = 0;
			for (int k=0; k<5; k++) {
				if(j*(1<<k)){
					val += a[i][k];
				}
				else {
					val -= a[i][k];
				}
			}
			b[i][j] = val;
		}
	}


}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++){
		for (int j=0; j<k; j++){
			cin >> a[i][j];
		}
	}
	make_tree();

	return 0;
}
