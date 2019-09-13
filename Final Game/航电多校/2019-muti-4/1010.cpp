// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int n = 4e3+5;
int a[n + 5];

inline int get3(int x) {
	int l = 1;
	int r = 1e6+5;
	while(l < r) {
		int mid = (l+r)/2;
		if (mid*mid*mid >= x)r = mid;
		else l = mid+1;
	}
	return l;
}

inline int get2(int x) {
	int l = 1;
	int r = 1e9+5;
	while(l < r) {
		int mid = (l+r)/2;
		if (mid*mid >= x)r = mid;
		else l = mid+1;
	}
	return l;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//O(n*lnlnn)
	vector<int> v;
	for (int i = 2; i <= n; i++)
		for (int j = i * 2; j <= n; j += i)
			a[j] = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] == 0) v.push_back(i);//素数 a[i]==0

	int t;
	cin >> t;
	while (t--) {
		int tp;
		cin >> tp;

		int mn = 2e18;
		for (int i=0; i<v.size(); i++){
			if (v[i] > tp) break;
			int cnt = 0;
			while (tp%v[i] == 0) {
				cnt++;
				tp/=v[i];
			}
			if (cnt != 0) mn = min(mn,cnt);
		}

		// findit
		if (tp == 1) {
			cout << mn << endl;
			continue;
		}

		// find min
		// tp > 4e3
		if (mn == 1) {
			cout << 1 << endl;
		}
		else {
			// after
			int mn2 = 1e18;

			int two = get2(tp);
			int four = get2(two);
			if (two*two == tp) {
				if (four*four == two) mn2 = min(mn2,4LL);
				else mn2 = min(mn2, 2LL);
			}
			else {
				int three = get3(tp);
				if (three*three*three == tp) {
					mn2 = min(mn2,3LL);
				}
				else {
					mn2 = min(mn2,1LL);
				}
			}

			mn = min(mn2,mn);
			cout << mn << endl;
		}
	}
	return 0;
}
