// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 112345;

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
		sum(p*2)+= add(p)*(r(p*2)-l(p*2)+1);
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


vector<int> lt(maxn);
vector<int> rt(maxn);

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}

	stack<pair<int,int>> st;
	st.push(make_pair(a[1],1));
	for (int i=2; i<=n; i++){
		while(!st.empty() && st.top().first%a[i] != 0) {
			rt[st.top().second] = i-1;
			st.pop();
		}
		st.push(make_pair(a[i],i));
	}
	while(!st.empty()) {
		rt[st.top().second] = n;
		st.pop();
	}

	st.push(make_pair(a[n],n));
	for (int i=n-1; i>=1; i--){
		while(!st.empty() && st.top().first%a[i] != 0) {
			lt[st.top().second] = i+1;
			st.pop();
		}
		st.push(make_pair(a[i],i));
	}
	while(!st.empty()) {
		lt[st.top().second] = 1;
		st.pop();
	}

	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		
	}
	return 0;
}
