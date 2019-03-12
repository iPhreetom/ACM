#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int sx,sy;
int ex,ey;
string s;
int now = 0;
int cnt = 0;

int n;
int index = 0;
int difx = 0;
int dify = 0;
int nowx = 0;
int x,y;


void movex() {
	x = sx, y = sy;
	if(sx < ex) {
		for (int i=0; i<s.size(); i++) {
			if(x == ex)break;
			cnt++;
			index++;
			if(s[i] == 'D') {
				y--;
				x++;
			}
			if(s[i] == 'U') {
				y++;
				x++;
			}
			if(s[i] == 'L') {

			}
			if(s[i] == 'R') {
				x++;
				if(x < ex) x++;
			}
		}
	}
	if(sx > ex) {
		for (int i=0; i<s.size(); i++) {
			if(x == ex)break;
			cnt++;
			index++;
			if(s[i] == 'D') {
				y--;
				x--;
			}
			if(s[i] == 'U') {
				y++;
				x--;
			}
			if(s[i] == 'L') {
				x--;
				if(x > ex) x--;
			}
			if(s[i] == 'R') {

			}
		}
	}
}

void movey() {
	cnt = 0;
	if(y < ey) {
		for (int i=0; i<s.size(); i++) {
			if(y == ey)break;
			cnt++;
			if(s[i] == 'D') {

			}
			if(s[i] == 'U') {
				y++;
				if(y < ey)y++;
			}
			if(s[i] == 'L') {

			}
			if(s[i] == 'R') {

			}
		}
	}
	if(y > ey) {
		for (int i=0; i<s.size(); i++) {
			if(y == ey)break;
			cnt++;
			if(s[i] == 'D') {
				y--;
				if(y > ey)y--;
			}
			if(s[i] == 'U') {

			}
			if(s[i] == 'L') {

			}
			if(s[i] == 'R') {

			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> sx >> sy >> ex >> ey;
	cin >> n;
	cin >> s;

	now = abs(sx-ex) + abs(sy-ey);
	nowx = abs(sx-ex);
	// first try x

	movex();

	difx = abs(x-sx);
	dify = y-sy;

	int need = abs(sx-ex) / difx; //  xuyao zhemeduoci shunfenzou
	int ans = cnt * need;
	x = (sx + (x-sx)*need);
	y = (sy + (y-sy)*need);

	cnt = 0;
	if(x != ex) {
		if(sx < ex) {
			for (int i=0; i<s.size(); i++) {
				if(x == ex) {
					string bk = s.substr(i);
					string ft = s.substr(0,i);
					s = bk+ft;
					break;
				}
				cnt++;
				index++;
				if(s[i] == 'D') {
					y--;
					x++;
				}
				if(s[i] == 'U') {
					y++;
					x++;
				}
				if(s[i] == 'L') {

				}
				if(s[i] == 'R') {
					x++;
					if(x < ex) x++;
				}
			}
		}
		if(sx > ex) {
			for (int i=0; i<s.size(); i++) {
				if(x == ex) {
					string bk = s.substr(i);
					string ft = s.substr(0,i);
					s = bk+ft;
					break;
				}
				cnt++;
				index++;
				if(s[i] == 'D') {
					y--;
					x--;
				}
				if(s[i] == 'U') {
					y++;
					x--;
				}
				if(s[i] == 'L') {
					x--;
					if(x > ex) x--;
				}
				if(s[i] == 'R') {

				}
			}
		}
	}
	ans += cnt;

	// second try
	cnt = 0;
	int nowy = y;
	movey();
	dify = abs(nowy-y);

	need = abs(y-ey) / dify;

	ans += cnt*()

	ans += cnt;

	cout << "ans = " << ans << endl;
	return 0;
}
