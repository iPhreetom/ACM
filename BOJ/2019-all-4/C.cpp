// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


int last;
const int maxn = 1e6+15;
struct node{
	int l,r;
	int sum,add;//区间求和
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define add(x) tree[x].add
	#define maxx(x) tree[x].mx
}tree[maxn*4];

int a[maxn];
int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		maxx(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	maxx(p) = max(maxx(p*2),maxx(p*2+1));
}

void spread(int p){
	if(add(p)){
		maxx(p*2) = add(p);
		maxx(p*2+1) = add(p);
		add(2*p) = add(p);
		add(2*p+1) = add(p);
		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		maxx(p) = d;
		add(p) = d;
		return ;
	}
	spread(p);

	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return maxx(p);
	}

	spread(p);
	int mid = (l(p)+r(p))/2;
	int val = -1e9;

	if(l<=mid)val = max( ask(p*2,l,r),val);
	if(r > mid)val = max(ask(p*2+1,l,r),val);
	return val;
}


void init() {
	memset(tree,0,min(sizeof(tree),8*last*sizeof(node)));
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while(cin >> n) {
		last = n;
		last += 10;
		stack<int> front;
		stack<int> back;

		int sum = 0;
		init();
		build(1,1,n);

		while(n--){
			char ch; cin >> ch;
			if (ch == 'I') {
				int val; cin >> val;
				front.push(val);
				sum += val;
				int index = front.size();
				change(1,index,index,sum);
			}
			else if (ch == 'L') {
				if (!front.empty()) {
					sum -= front.top();
					change(1,front.size(),front.size(),0);
					back.push(front.top());
					front.pop();
				}
			}
			else if (ch == 'R') {
				if (!back.empty()) {
					sum += back.top();
					front.push(back.top());
					change(1,front.size(),front.size(),sum);
					back.pop();
				}
			}
			else if (ch == 'Q') {
				int k; cin >> k;
				cout << ask(1,1,k) << endl;
			}
			else if (ch == 'D') {
				if (!front.empty()) {
					sum -= front.top();
					change(1,front.size(),front.size(),0);
					front.pop();
				}
			}
		}
	}
	return 0;
}
