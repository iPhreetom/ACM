#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<string> mp(5123);
int n, m;
int cnt = 0;

bool tryit(int x,int y) {
	int now = 1;
	if (mp[x+1][y] != '*') return 0;
	if (mp[x-1][y] != '*') return 0;
	if (mp[x][y+1] != '*') return 0;
	if (mp[x][y-1] != '*') return 0;

	for (int i=x+1; i<n; i++) {
		if (mp[i][y] == '*') {
			now++;
		}
		else break;
	}
	for (int i=x-1; i>=0; i--) {
		if (mp[i][y] == '*') {
			now++;
		}
		else break;
	}
	for (int i=y+1; i<m; i++) {
		if (mp[x][i] == '*') {
			now++;
		}
		else break;
	}
	for (int i=y-1; i>=0; i--) {
		if (mp[x][i] == '*') {
			now++;
		}
		else break;
	}
 	if (now == cnt) return 1;
	else return 0;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> mp[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (mp[i][j] == '*') cnt++;
		}
	}
	if (cnt < 5) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i=1; i<n-1; i++) {
		for (int j=1; j<m-1; j++) {
			if (mp[i][j] == '*' && tryit(i,j)) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
