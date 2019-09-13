// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int add[1123456],mid[1123456],sub[1123456];
int l[312345],r[312345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	vector<pair<int,int>> lis;
	for (int i=1; i<=n; i++){
		cin >> l[i] >> r[i];
		l[i]*=2;
		r[i]*=2;
		sum += r[i]-l[i];
		lis.push_back({l[i],1});
		lis.push_back({r[i],1});
		lis.push_back({(r[i]+l[i])/2,-2});
	}

	sort(lis.begin(),lis.end());
	// lis.erase(unique(lis.begin(),lis.end()),lis.end());

	int cnt = 0;

	int now = 0;
	int mx = 0;
	int all = 0;
	int last = 0;
	for (int i=0; i<lis.size(); i++){
		all += now*(lis[i].first-last);
		mx = max(mx,all);
		last = lis[i].first;
		now += lis[i].second;
	}

	cout << mx << endl;
	return 0;
}
