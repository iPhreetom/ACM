// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<int,int> mp;
vector<int> ans;
int f = 0;
bool check(int m) {
	int tp = f;
	map<int,int> mp2 = mp;
	ans.clear();
	ans.push_back(tp);

	mp2[tp]--;
	for (int i=0; i<n-1; i++){
		if(mp2[tp-m] > 0) {
			ans.push_back(tp-m);
			mp2[tp-m]--;
		}
		else {
			if(mp2[tm] > 0) {
				ans.push_back(tp+m);
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin >> a[i];
		mp[a[i]] ++;
		f = a[i];
	}
	sort(a.begin(),a.end());
	int mx = a.back() - a.front();
	int l = 0;
	int r = mx+1;
	while(l + 1 < r) {
		int mid = l + (r-l)/2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	if(check(l)) {

	}
	else {

	}
	return 0;
}
