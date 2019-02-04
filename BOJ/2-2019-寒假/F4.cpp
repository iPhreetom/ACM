// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
typedef pair<pair<int,int>,int> pii;

int n, m;
int a[212345];
int b[212345];
pii lis[212345];
vector<pii> order_by_y;

set<pair<int,pii>> s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// 换系
	// 不扫坐标
	// 扫时间
	// 相当于把时间当做横轴
	// 操作变成纵轴

	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	for (int i=1; i<=n; i++){
		cin >> b[i];
	}

	for(int t=1; t<=m; t++) {
		int x, y, k;
		cin >> x >> y >> k;
		lis[t] = make_pair(make_pair(y, x), k);
		order_by_y.push_back(make_pair(make_pair(y, x), k));
	}



	return 0;
}
