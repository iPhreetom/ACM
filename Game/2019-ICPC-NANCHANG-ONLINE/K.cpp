#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> v;
vector<int> pre;
void init() {

}
int getAns() {
		
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		v.resize(n+1, 0);
		for (int i=1; i<=n; i++) {
		    cin >> v[i];
		}
		init();

		int q;
		cin >> q;
		while (q--) {
			int l,r;
			cin >> l >> r;
			cout << getAns() << endl;
		}
	}
	return 0;
}
