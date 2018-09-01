const int maxn = 112345;

struct node{
	int l,r;
	int maxx,add;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define maxx(x) tree[x].maxx
	#define add(x) tree[x].add
}tree[maxn*4];

int a[maxn];

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


void change(int p,int l,int r,int d){
	if(l(p) == r(p)){
		maxx(p) = d;
		return ;
	}
	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);
	maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int ask(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return maxx(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = -1e17;
	if(l<=mid)val = max(val,ask(p*2,l,r));
	if(r > mid)val = max(val,ask(p*2+1,l,r));
	return val;
}
