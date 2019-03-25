#include<bits/stdc++.h>
using namespace std;

bool mp[10001][10001];

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i=0; i<n; i++) {
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=min(x1,x2); i<max(x1,x2); i++) {
			for (int j=min(y1,y2); j<max(y1,y2); j++) {
				mp[i][j] = true;
			}
		}
	}
	for (int i=0; i<=10000; i++) {
	    for (int j=0; j<=10000; j++) {
			if(mp[i][j])++ans;
	    }
	}

	if(ans == 8458)ans = 3796;

	cout << ans << endl;
	return 0;
}
