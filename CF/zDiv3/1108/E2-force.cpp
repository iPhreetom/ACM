枚举每一位置是答案，然后处理，优化
#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

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
		minn(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	minn(p) = min(minn(p*2),minn(p*2+1));
}

void spread(int p){
	if(add(p) != 0){
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
	int val = 1e9;

	if(l<=mid)val = min(val,ask(p*2,l,r));
	if(r > mid)val = min(ask(p*2+1,l,r),val);

	return val;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;

	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	build(1,1,n);

	vector<pair<int,int>> lis;
	for (int i=1; i<=q; i++){
		int l,r;
		cin>>l>>r;
		lis.push_back(make_pair(l,r));
	}

	vector<bool> ans(q,0);
	vector<bool> vis(q,0);
	int mx = 0;
	for (int i=1; i<=n; i++){
		for (int j=0; j<lis.size(); j++){
			int &l = lis[j].first;
			int &r = lis[j].second;
			if(vis[j] && l <= i && r >= i) {
				vis[j] = 0;
				change(1,l,r,1);
			}
			else if(l > i && !vis[j]) {
				vis[j] = 1;
				change(1,l,r,-1);
			}
			else if(r < i && !vis[j]) {
				vis[j] = 1;
				change(1,l,r,-1);
			}
			// cout<<"j = "<<j<<endl;
			// for (int i=1; i<=n; i++){
			//     cout << ask(1,i,i) << ' ';
			// }cout << endl;
		}

		if(i == 1) {
			if(i != n) {
				// cout<<"ask(1,i+1,n) = "<<ask(1,i+1,n)<<endl;
				int now = a[i] - ask(1,i+1,n);
				if(now > mx) {
					for (int j=0; j<vis.size(); j++){
						ans[j] = vis[j];
					}
					mx = now;
				}
			}
		}
		else {
			int rt = 0;
			if(i != n) {
				rt = a[i] - ask(1,i+1,n);
			}
			int lt = a[i] - ask(1,1,i-1);
			int now = max(lt,rt);
			if(now > mx) {
				for (int j=0; j<vis.size(); j++){
					ans[j] = vis[j];
				}
				mx = now;
			}
		}
		// cout<<"mx = "<<mx<<endl;
		// for (int j=0; j<vis.size(); j++){
		// 	cout<< vis[j] << ' ';
		// }cout << endl;
	}

	cout << mx << endl;
	int cnt = 0;
	for (int j=0; j<ans.size(); j++){
		if(ans[j]) cnt++;
	}
	cout << cnt << endl;
	for (int j=0; j<ans.size(); j++){
		if(ans[j]) cout << j+1 << ' ';
	}cout << endl;
	return 0;
}
