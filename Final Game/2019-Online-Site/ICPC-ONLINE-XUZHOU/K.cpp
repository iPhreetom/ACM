// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<pair<int,int>,int> mp;
int x[2123];
int y[2134];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> x[i] >> y[i];
		x[i] *= 2;
		y[i] *= 2;
		mp[make_pair(x[i],y[i])]++;
	}

	int mx = 1;
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++){
			int cx = (x[i]+x[j])/2;
			int cy = (y[i]+y[j])/2;
			mp[make_pair(cx,cy)]+=2;
			mx = max(mp[make_pair(cx,cy)],mx);
		}
	}

	cout << max(0LL,n-mx) << endl;
	return 0;
}
