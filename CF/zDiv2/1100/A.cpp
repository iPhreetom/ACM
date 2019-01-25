// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, k;
int a[2123];

int solve(int index) {
	int e = 0, s = 0;
	for (int i=1; i<=n; i++){
		if( abs(i-index) % k != 0) {
			if(a[i] == 1) e++;
			else s++;
		}
	}
	return abs(s-e);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for (int i=1; i<=n; i++){
		ans = max(ans,solve(i));
	}
	cout << ans << endl;
	return 0;
}
