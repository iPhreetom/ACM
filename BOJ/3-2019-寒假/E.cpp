// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[2123456];
vector<int> num[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (num[a[i]].empty()) {
			num[a[i]].push_back(0);
		}
		num[a[i]].push_back(i);
	}

	int sum = 0;
	for (int i=1; i<=1e6; i++) {
		if (!num[i].empty()) {
			num[i].push_back(n+1);
			for (int j=1; j<num[i].size()-1; j++) {
				int lt = num[i][j] - num[i][j-1];
				int all = lt*rt;
				
				sum += all;
			}
		}
	}
	double ans = sum;
	double dinominator = n*n;
	cout << fixed << setprecision(12) << ans/dinominator << endl;
	//
	// 3 _ 3
	// 3 + 4 + 5
	return 0;
}
