#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 301010;
int n, m;
int rson[N*20], lson[N*20], sum[N*20], root[N];
int arr[N], brr[N], tot;
int vis[N];
int res;
void update(int pre, int &rt, int l, int r, int k, int v)
{
    rt = ++tot;
    lson[rt] = lson[pre], rson[rt] = rson[pre], sum[rt] = sum[pre] + v;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(k <= mid) update(lson[pre], lson[rt], l, mid, k, v);
    else update(rson[pre], rson[rt], mid + 1, r, k, v);
}
void query(int rt, int l, int r, int k)
{
    if(k == l)
    {
        res += sum[rt];
        return;
    }
    int mid = (l + r) >> 1;
    if(k <= mid) res += sum[rson[rt]], query(lson[rt], l, mid, k);
    else query(rson[rt], mid + 1, r, k);
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    tot = 0;
	cin >> n;
    for(int i = 1;i <= n;i++) {
		cin >> arr[i];
		brr[i] = arr[i];
	}
	sort(brr + 1, brr + 1 + n);
    int len = unique(brr + 1, brr + 1 + n) - brr - 1;
    memset(vis, -1, sizeof vis);
    int tmp;
	for (int i=1; i<=n; i++) {
		arr[i] = lower_bound(brr + 1, brr + 1 + len, arr[i]) - brr;
		if(vis[arr[i]] == -1) update(root[i-1], root[i], 1, n, i, 1);//之前不存在当前元素，直接插入树中
		else update(root[i-1], tmp, 1, n, vis[arr[i]], -1), update(tmp, root[i], 1, n, i, 1); //当前元素在树中以存在，用新建节点的方式删除之前的，再插入
		vis[arr[i]] = i;
	}
	int q;
	cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
		res = 0;
		query(root[r], 1, n, l);
        cout << res << endl;
    }
    return 0;
}
