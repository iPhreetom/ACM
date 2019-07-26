// fyt
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

const int maxn = 312345;
int x,ql,qr;
struct node{
	int l,r;
	int add;//区间求和
	int mn;
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
		minn(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	minn(p) = min(minn(p*2),minn(p*2+1));
}

void spread(int p){
	if(add(p)){
		minn(p*2) += add(p);
		minn(p*2+1) += add(p);

		add(2*p) += add(p);
		add(2*p+1) += add(p);

		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		minn(p) += d;
		add(p) += d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	minn(p) = min(minn(2*p),minn(2*p+1));
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return minn(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = 2e18;

	if(l<=mid)val = min(val,ask(p*2,l,r));
	if(r > mid)val = min(val,ask(p*2+1,l,r));

	return val;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}

	int ans = 0;
	x = k;
	for (int j=1; j<=m; j++){
        memset(tree,0,sizeof(tree));
		build(1,1,n);
		if (j != 1) {
			ql = 1; qr = j-1;
			change(1,ql,qr,k);
		}
		for (int i=j; i<=n; i+=m){
			if (i != j) {
				ql = 1; qr = i-1;
				change(1,ql,qr,k);
				ans = max(ans,a[i]-ask(1,ql,qr));
                ans = max(ans,a[i]-((i+m-1)/m)*k);
			}
			else {
				if (j == 1) ans = max(ans,a[1]-k);
				else {
					ql = 1; qr = j-1;
					ans = max(ans,a[i]-ask(1,ql,qr));
                    ans = max(ans,a[i]-((i+m-1)/m)*k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
