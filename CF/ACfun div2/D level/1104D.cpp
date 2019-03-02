#include<bits/stdc++.h>
using namespace std;

string s;
void solve() {
	int x = 1;
	int lx = 0;
	while(1) {
		cout << "? " << lx << ' ' << x <<endl;
		cin >> s;
		if(s == "x") {
			if(x - lx <= 1) {
				cout << "! " << x <<endl;
				return ;
			}
			else {
				int l = lx;
				int r = x;
				while(l+1 < r) {
					int mid = l + (r-l)/2;
					cout << "? " << lx << ' ' << mid <<endl;
					cin >> s;
					if(s == "x") {
						r = mid;
					}
					else {
						l = mid;
					}
				}
				cout << "! " << r << endl;
				return ;
			}
		}
		else {
			lx = x;
			x = 2*x;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	while(1) {
		cin >> s;
		if(s == "start") {
			solve();
		}
		else break;
	}

	return 0;
}
