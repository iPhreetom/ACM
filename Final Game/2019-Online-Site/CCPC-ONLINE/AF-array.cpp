// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e5+7;
int inf;
int T[maxn*5];

void modif(int l,int r,int id,int pos,int det) {
	if (l == r) {
		T[id] = det;
		return;
	}
	int mid=(l+r)>>1, lid=id<<1, rid=(id<<1)+1;
	if (pos <= mid) modif(l,r,lid,pos,det);
	else modif(l,r,rid,pos,det);
	T[id] = max(T[lid],T[rid]);
}

int query(int l,int r,int id,int p,int k) {
	if (k > r) return inf;
	if (l==r) {
		if (T[id]>=p) return l;
		return inf;
	}
	int mid=(l+r)>>1, lid=id<<1, rid=(id<<1)+1;
	if ()
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int cas;
	cin >> cas;
	while(cas--) {
		int n,q;
		cin >> n >> q;
		for (int i=1; i<=n; i++){
			int t;
			cin >> t;

		}
	}
	return 0;
}
