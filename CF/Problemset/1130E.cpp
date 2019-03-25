#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int k;
void PlanA() {
	cout << -1 << ' ' << k+2 << endl;
}

void PlanB() {
	bool ok = 0;
	for (int i=2; i<=2000; i++) {
		if( k%i == 0 && k/i <= (1e6-1)) {
			ok = 1;
			int len = i;
			int val = k/i;
			for (int j=1;j<=len-2; j++){
				cout << 0 << ' ';
			}
			cout << -1 << ' ';
			cout << val+1 << endl;
			break;
		}
	}
	if(!ok){
		cout << -1 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> k;
	for (int n = 2; n<=2000; n++) {
		int val = k+n;
		int maxS = (n-1)*1e6 - 1;
		if(val <= maxS) {
			cout << n << endl;
			cout << -1 ;
			for (int i=0; i<n-1; i++) {
				cout << ' ' << min(1000000LL, val);
				val -= min(1000000LL, val);
			}
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
