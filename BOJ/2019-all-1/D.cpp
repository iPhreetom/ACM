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

const int maxn = 112345;

struct node{
	int l,r;
	int sum;//区间求和
	tuple<int,int,int> mx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define maxx(x) tree[x].mx
}tree[maxn*4];

int a[maxn];
int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		maxx(p) = {a[l],l,1};
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);

	maxx(p) = min(maxx(p*2),maxx(p*2+1));
	if (get<0>(maxx(p*2)) == get<0>(maxx(p*2+1)))
		maxx(p) = {get<0>(maxx(p)),
				get<1>(maxx(p)),
				get<2>(maxx(p*2))+get<2>(maxx(p*2+1))};
}

tuple<int,int,int> askmn(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return maxx(p);
	}

	int mid = (l(p)+r(p))/2;
	tuple<int,int,int> val = {1e18,1e18,1e18};

	if(l<=mid) {
		tuple<int,int,int> lt = askmn(p*2,l,r);
		if (get<0>(val) == get<0>(lt) )
			val = {get<0>(val),get<1>(val),get<2>(val)+get<2>(lt)};
		else val = min(val,lt);
	}
	if(r > mid) {
		tuple<int,int,int> rt = askmn(p*2+1,l,r);
		if (get<0>(val) == get<0>(rt) )
			val = {get<0>(val),get<1>(val),get<2>(val)+get<2>(rt)};
		else val = min(val,rt);
	}

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
		while(!st.empty() && a[i]%st.top().first != 0) {
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
		while(!st.empty() && a[i]%st.top().first != 0) {
			lt[st.top().second] = i+1;
			st.pop();
		}
		st.push(make_pair(a[i],i));
	}
	while(!st.empty()) {
		lt[st.top().second] = 1;
		st.pop();
	}
	//
	// for (int i=1; i<=n; i++){
	// 	cout << lt[i] << ' ';
	// }cout << endl;
	// for (int i=1; i<=n; i++){
	// 	cout << rt[i] << ' ';
	// }cout << endl;
	// cout << endl;

	build(1,1,n);
	int t;
	cin >> t;
	while(t--){
		int l,r;
		cin >> l >> r;
		int sum = r-l+1;
		auto p = askmn(1,l,r);
		int mx = get<0>(p);
		int index = get<1>(p);
		int cnt = get<2>(p);
		// cout<<"mx = "<<mx<<endl;
		// cout<<"index = "<<index<<endl;
		// cout<<"cnt = "<<cnt<<endl;
		if (lt[index]<=l && rt[index] >= r) sum -= cnt;
		cout << sum << endl;
	}
	return 0;
}
