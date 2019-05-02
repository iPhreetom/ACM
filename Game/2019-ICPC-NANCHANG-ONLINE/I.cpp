#include<bits/stdc++.h>
#define int long long
#define EDl '\n'
using namespace std;

vector<int> v;
vector<int> pre;
vector<int> ST;
vector<int> ED;
int n;
int ans_mx = 0;

const int maxn = 512345;
const int MAXN = 512345;
struct node{
	int l,r;
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define minn(x) tree[x].mn
}tree[maxn*4];

struct node2{
	int l,r;
	int mn,mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define minn(x) tree[x].mn
}tree2[maxn*4];

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		minn(p) = pre[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	minn(p) = min(minn(p*2),minn(p*2+1));
}
int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return minn(p);
	}

	int mid = (l(p)+r(p))/2;
	int val = 1e18;

	if(l<=mid)val = min(val,ask(p*2,l,r));
	if(r > mid)val = min(val,ask(p*2+1,l,r));

	return val;
}

void build2(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		minn(p) = pre[l];
		return ;
	}
	int mid = (l+r)/2;
	build2(p*2,l,mid);
	build2(p*2+1,mid+1,r);
	minn(p) = min(minn(p*2),minn(p*2+1));
}
int ask2(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return minn(p);
	}

	int mid = (l(p)+r(p))/2;
	int val = 1e18;

	if(l<=mid)val = min(val,ask2(p*2,l,r));
	if(r > mid)val = min(val,ask2(p*2+1,l,r));

	return val;
}

int doing(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++)
		ST[i]=ED[i]=i;
	stack<int> sta;
	int i=l;
	while(i<=r){
		if(sta.empty()||v[i]>v[sta.top()]){
			sta.push(i);
			++i;
		}
		else{
			ST[i]=ST[sta.top()];
			sta.pop();
		}
	}
	while(!sta.empty())
		sta.pop();
	i=r;
	while(i>=l){
		if(sta.empty()||v[i]>v[sta.top()]){
			sta.push(i);
			--i;
		}
		else{
			ED[i]=ED[sta.top()];
			sta.pop();
		}
	}
	//for(int i=l;i<=r;i++)cout<<ST[i]<<' ';cout<<EDl;
	//for(int i=l;i<=r;i++)cout<<ED[i]<<' ';cout<<EDl;
	for(int i=l;i<=r;i++){
		int L=ST[i],R=ED[i];
		int tmp= v[i]*(pre[R]-pre[L-1]);
//		printf("v[%d]=%d  pre[R=%d]-pre[L-1=%d]=%d",i,v[i],R,L-1,pre[R]-pre[L-1]);
		ans=max(ans,tmp);
//		cout<<"    i="<<i<<"  tmp="<<tmp<<EDl;
	}
	return ans;
}
int get_max(int n){
	// cout << "n = " << n << EDl;
	ST.resize(maxn,0);
	ED.resize(maxn,0);
	int ans=0;
	int l,r;
	// cout<<"-------------"<<EDl;
	for(int i=1;i<=n;i++){
		if(i==1||(v[i-1]<0&&v[i]>0&&i>1)){
			l=i;
		}
		if(i==n||(v[i+1]<0&&v[i]>0&&i<n)){
			r=i;
			// cout<<"l="<<l<<"  r="<<r<<EDl;
			int tmp=doing(l,r);
			// cout<<"yes"<<EDl;
			ans=max(ans,tmp);
		}
	}
	return ans;
}

bool find_negetive() {
	for (int i=1; i<=n; i++) {
		if(v[i] <= 0) {
			return 1;
		}
	}
	return 0;
}
int get_max_negetive() {
	if(!find_negetive()) return 0;

	// v.push_back(1);
	build(1,1,n);

	int que_sum = 0;
	int que_mn = 1e18;
	int ans = 0;
	int cnt = 0;

	for (int i=1; i<=n; i++) {
		if (v[i] > 0) {
			if(cnt == 0)continue;
			int val = que_sum;
			int mn = ask(1,i,n)-pre[i-1];
			if(mn < 0) {
				val += mn;
			}
			ans = max(ans,val*que_mn);

			// reset
			que_sum = 0;
			que_mn = 1e18;
			cnt = 0;
		}
		else {
			que_sum += v[i];
			que_mn = min(que_mn, v[i]);
			cnt++;
			if (i == n) {
				int val = que_sum;
				ans = max(ans,val*que_mn);
			}
		}
	}

	queue<int> que;
	que_sum = 0;
	que_mn = 1e18;
	for (int i=1; i<=n; i++) {
		if(v[i] > 0) {
			que_sum += v[i];
			que.push(v[i]);
			if(que_sum > 0){
				que_sum = 0;
				que_mn = 1e18;
				while(!que.empty()){
					que.pop();
				}
			}
		}
		else {
			que_sum += v[i];
			que_mn = min(que_mn,v[i]);
			ans = max(ans,que_mn * que_sum);
		}
	}

	return ans;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	v.resize(n+1);
	v[0] = 0;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
	}

	if (n == 1) {
		cout << v[1]*v[1] << EDl;
		return 0;
	}

	pre.resize(n+2,0);
	pre[0] = 0;
	for (int i=1; i<=n+1; i++) {
		pre[i] = pre[i-1]+v[i];
	}

	int vala = get_max(n);
	int valb = get_max_negetive();
	cout << max(vala,valb) << EDl;
	return 0;
}
