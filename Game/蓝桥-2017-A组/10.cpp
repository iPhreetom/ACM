#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int l,r;
	int len = 0;
	int cnt = 0;
}tree[412345];

void build(int p, int l,int r) {
	tree[p].l = l;
	tree[p].r = r;

	if(l == r) {
		tree[p].len = 0;
		tree[p].cnt = 0;
		return ;
	}

	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}


void change(int p, int l, int r, int val) {
	// cout << "p = " << p << endl;
	if(l <= tree[p].l && tree[p].r <= r) {
		if(val == 1) {
			tree[p].cnt++;
		}
		else {
			tree[p].cnt--;
		}

		if(tree[p].cnt > 0) {
			tree[p].len = tree[p].r - tree[p].l + 1;
		}
		else {
			tree[p].len = tree[p*2].len + tree[p*2+1].len;
		}

		return ;
	}

	int mid = (tree[p].l + tree[p].r)/2;

	if(l <= mid) change(p*2,l,r,val);
	if(mid+1 <=r) change(p*2+1,l,r,val);

	if(tree[p].cnt > 0) {
		tree[p].len = tree[p].r - tree[p].l + 1;
	}
	else {
		tree[p].len = tree[p*2].len + tree[p*2+1].len;
	}
}

vector<vector<pair<int,int> > > add(112345);
vector<vector<pair<int,int> > > del(112345);

signed main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i=0; i<n; i++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 == y2)continue;
		if(x1 == x2)continue;
		if(x1 > x2)swap(x1,x2);
		if(y1 > y2)swap(y1,y2);
		y1++;
		y2++;
		y2--;
		add[x1].push_back(make_pair(y1,y2));
		del[x2].push_back(make_pair(y1,y2));
	}
	build(1,1,100005);

	for (int i=0; i<=100005; i++) {
		for (int j=0; j<del[i].size(); j++) {
			change(1, del[i][j].first, del[i][j].second, -1);
		}
		for (int j=0; j<add[i].size(); j++) {
			change(1, add[i][j].first, add[i][j].second, 1);
		}
		ans += tree[1].len;
	}

	cout << ans << endl;
	return 0;
}
