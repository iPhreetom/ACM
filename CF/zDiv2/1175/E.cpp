// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int nt[512345][22];
int val[512345];
int n,m;

void init() {
	int mx = 0;
	for (int i=0; i<512345; i++){
		mx = max(mx,val[i]);
		if (mx == i) mx = 0;
		val[i] = mx;
	}
	for (int i=0; i<512345; i++){
	    nt[i][0] = val[i];
	}
	for (int i=1; i<22; i++){
		for (int j=0; j<512345; j++){
			if (nt[j][i-1] != 0) nt[j][i] = nt [nt[j][i-1]] [i-1];
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		int l,r;
		cin >> l >> r;
		val[l] = r;
		// que.push(make_pair(l,r));
	}
	init();
	while (m--) {
		int x,y;
		cin >> x >> y;

		int cnt = 0;
		for (int i=21; i>=0; i--) {
			if(nt[x][i] == 0) continue;
			if (nt[x][i] >= y) continue;
			else { // nt[x][i] < y
				x = nt[x][i];
				cnt |= (1<<i);
			}
		}

		if (nt[x][0] < y) {
			cout << -1 << endl;
		}
		else {
			cout << cnt+1 << endl;
		}

	}
	return 0;
}
