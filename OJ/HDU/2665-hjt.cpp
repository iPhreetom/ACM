// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 5;
int a[N], b[N], rt[N * 20], ls[N * 20], rs[N * 20], sum[N * 20];
int n, k, tot, sz, ql, qr, x, q, T;

void Build(int& o, int l, int r){
    o = ++ tot;
    sum[o] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    Build(ls[o], l, m);
    Build(rs[o], m + 1, r);
}

void update(int& o, int l, int r, int last, int p){
    o = ++ tot;
    ls[o] = ls[last];
    rs[o] = rs[last];
    sum[o] = sum[last] + 1;
    if(l == r) return;
    int m = (l + r) >> 1;
    if(p <= m)  update(ls[o], l, m, ls[last], p);
    else update(rs[o], m + 1, r, rs[last], p);
}

int query(int ss, int tt, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r) >> 1;
    int cnt = sum[ls[tt]] - sum[ls[ss]];
    if(k <= cnt) return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m + 1, r, k - cnt);
}





signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for (int i=1; i<=n; i++){
			cin>>a[i];
		}
		while(m--){
			int l,r,k;
			cin>>l>>r>>k;
		}
	}
	return 0;
}
