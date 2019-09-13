// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lowbit(int x) { return x & (-x); }

int getit(int x) {
	int tp = 1;
	while(tp <= x) tp *= 2;
	tp -= 1;
	return x^tp;

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;

	unordered_set<int> s;
	int tp = 2;
	while(tp < 1e18) {
		tp *= 2;
		s.insert(tp-1);
	}

	while (T--) {
		int n;
		cin >>n;
		if (s.count(n)!=0){
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}

		for (int i=2; i<=n; i++){
			if (lowbit(getit(i))==0) {
				if (i!=n) cout << i+1 << (i==n?'\n':' ');
				else cout << 1 << (i==n?'\n':' ');
			}
			else {
				cout << lowbit(getit(i)) << (i==n?'\n':' ');
			}
		}
	}

	return 0;
}
