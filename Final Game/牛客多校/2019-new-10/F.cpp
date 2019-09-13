// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int maxn = 312345;

struct node{
	int l,r;
	int add;//区间求和
	int mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define add(x) tree[x].add
	#define maxx(x) tree[x].mx
}tree[maxn*4];

int a[maxn];
int n,dis;

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
		maxx(p*2) += add(p);
		maxx(p*2+1) += add(p);

		add(2*p) += add(p);
		add(2*p+1) += add(p);

		add(p) = 0;
	}
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		maxx(p) += d;
		add(p) += d;
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
	int val = 0;
	if(l<=mid)val = max(val,ask(p*2,l,r));
	if(r > mid)val = max(val,ask(p*2+1,l,r));

	return val;
}

const int len = 1e5+10;
vector<int> mp[312345];
int val[312345];

void delx(int x) {
	for (int i=0; i<mp[x].size(); i++) {
		int cnt = 0;
		for (int k=mp[x][i]; k>=1; k-=dis) {
			change(1,k,k,-1);
			cnt++;
			if (cnt == 3) break;
		}
	}
}

void putx(int x) {
	for (int i=0; i<mp[x].size(); i++) {
		int cnt = 0;
		for (int k=mp[x][i]; k>=1; k-=dis) {
			change(1,k,k,1);
			cnt++;
			if (cnt == 3) break;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> dis;
	build(1,1,311111);
	for (int i=1; i<=n; i++){
		int x,y;
		cin >> x >> y;
		x++;
		y++;
		change(1,y,y,1);
		mp[x].push_back(y);
	}

	// init x
	for (int i=1; i<=len; i++) {
		for (int j=0; j<3; j++) {
			int index = i+j*dis;
			val[i] += mp[index].size();
		}
	}


	// init y
	for (int i=1; i<=len; i++){
		for (int j=1; j<3; j++) {
			int nextintdex = i+dis*j;
			change(1,i,i,ask(1,nextintdex,nextintdex));
		}
	}

	// init_val
	int ans = 0;
	//！！！！！！！！！！！！
	for (int i=1; i<=len; i++) {
		// cout << "________" << endl;
		// for (int j=1; j<=11; j++){
		// 	cout<<"ask(1,j,j) = "<<ask(1,j,j)<<endl;
		// }
		// cout << "____" << endl;
		for (int j=0; j<3; j++){
			delx(i+j*dis);
		}
		// for (int j=1; j<=11; j++){
		// 	cout<<"ask(1,j,j) = "<<ask(1,j,j)<<endl;
		// }
		int now = val[i] + ask(1,1,len);
		// if(val[i] != 0) {
		// 	cout<<"i = "<<i<<endl;
		// 	cout<<"now = "<<now<<endl;
		// 	cout<<"val[i] = "<<val[i]<<endl;
		// 	cout << endl;
		// }
		ans = max(now,ans);
		for (int j=0; j<3; j++){
			putx(i+j*dis);
		}
	}

	cout << ans << endl;
	return 0;
}
