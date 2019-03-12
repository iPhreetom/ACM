#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int sx,sy;
int ex,ey;
string s;
int n;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> sx >> sy >> ex >> ey;
	cin >> n;
	cin >> s;

	int x = 0, y = 0;
	for (int i=0; i<s.size(); i++) {
		if(s[i] == 'D') {
			y--;
		}
		if(s[i] == 'U') {
			y++;
		}
		if(s[i] == 'L') {
			x--;
		}
		if(s[i] == 'R') {
			x++;
		}
	}

	int mx = 2e9;
	int tx = sx + mx*x;
	int ty = sy + mx*y;
	int dif = abs(tx-ex) + abs(ty-ey);
	if(dif > mx*n) {
		cout << -1 << endl;
		return 0;
	}

	int l = 1, r = mx+1;
	while (l + 1 < r) {
		int mid = l + (r-l)/2;
		int tx = sx + mid*x;
		int ty = sy + mid*y;
		int dif = abs(tx-ex) + abs(ty-ey);
		if(dif > mid*n) {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	tx = sx + l*x;
	ty = sy + l*y;
	dif = abs(tx-ex) + abs(ty-ey);

	if(dif > l*n) {
		// r
		tx = sx + r*x;
		ty = sy + r*y;
		dif = abs(tx-ex) + abs(ty-ey);
		if(dif == r*n) {
			cout << r*n << endl;
		}
		else {
			x = sx+(r-1)*x;
			y = sy+(r-1)*y;
			int cnt = (r-1)*n;
			for (int i=0; i<s.size(); i++) {
				cnt++;
				if(s[i] == 'D') {
					y--;
				}
				if(s[i] == 'U') {
					y++;
				}
				if(s[i] == 'L') {
					x--;
				}
				if(s[i] == 'R') {
					x++;
				}
				dif = abs(x-ex) + abs(y-ey);
				if(dif <= cnt) {
					cout << cnt << endl;
					return 0;
				}
			}
		}
	}
	else {
		if (dif == l*n) {
			cout << n*l << endl;
		}
		else {
			// L-1
			x = sx+(l-1)*x;
			y = sy+(l-1)*y;
			int cnt = (l-1)*n;
			for (int i=0; i<s.size(); i++) {
				cnt++;
				if(s[i] == 'D') {
					y--;
				}
				if(s[i] == 'U') {
					y++;
				}
				if(s[i] == 'L') {
					x--;
				}
				if(s[i] == 'R') {
					x++;
				}
				dif = abs(x-ex) + abs(y-ey);
				if(dif <= cnt) {
					cout << cnt << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}
