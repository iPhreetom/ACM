// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// sync fi	ght
int big[1123456];
bool sync[1123456];
int pre[1123456];
int v[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x,y;
	cin >> n >> x >> y;

	string gege;
	string didi;
	gege = "Vanya";
	didi = "Vova";
	if (x < y) swap(gege,didi);
	int mn = min(x,y);
	int mx = max(x,y);

	for (int i=1; i<=mn; i++){
		big[i] = big[i-1]+mx/mn;
		while ((big[i]+1)*mn <= i*mx) big[i]++;
		if (big[i] * mn == i*mx) sync[i] = true;
	}
	for (int i=1; i<=mn; i++){
		big[i]++;
	}

	for (int i=1; i<=n; i++){
		cin >> v[i];
	}

	int res = 0;
	int last = 0;
	bool put = 0;

	for (int i=1; i<=n; i++){
		v[i] -= v[i]/(x+y)*(x+y);
		if ((res == v[i] && !sync[last]) || res > v[i]) {
			cout << gege << endl;
			res -= v[i];
		}
		else if (res == v[i] && sync[last]) {
			cout << "Both" << endl;
			res -= v[i];
		}
		else if (res == v[i]) {
			cout << didi << endl;
			res -= v[i];
		}
		else {
			int tp = lower_bound(big+1,big+mn+1,v[i])-big;

		}
	}

	return 0;
}
