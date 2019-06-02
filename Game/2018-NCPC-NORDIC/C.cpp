// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool check(vector<int> v, int d) {
	int cnt = 0;
	for (int i=0; i<v.size(); i++){
	    cnt += d-v[i];
	}
	if (cnt < 20) return true;
	else return false;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int cnt = 0;
	vector<int> lis;

	for (int i=1; i<=n; i++){
		int d;
		cin >> d;

		if (check(lis,d)) {
			lis.push_back(d);\
		}
		else {
			lis.clear();
			lis.push_back(d);
			ans++;
		}
	}
	if (!lis.empty()) ans++;
	cout << ans << endl;
	return 0;
}
