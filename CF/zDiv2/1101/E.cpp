#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int mx = 0;
	int my = 0;
	while ( n -- ) {
		string ch;
		int x, y;
		cin >> ch >> x >> y;
		if(ch == "+") {
			if(y > x) swap(x, y);
			mx = max(mx, x);
			my = max(my, y);
		}
		else {
			if(y > x) swap(x, y);
			if(mx <= x && my <= y){
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
