// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool check(int p) {
	if (p < 2) return false;
	for (int i=2; i<=sqrt(p); i++){
		if (p%i == 0) return false;
	}

	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	int edge = -1;
	for (int i=n; i<=n+(n/2); i++){
		if (check(i)) {
			edge = i;
			break;
		}
	}
	if (edge == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << edge << endl;
	for (int i=1; i<=n; i++){
		cout << i << ' ' << (((i+1)%(n+1)==0)?1:(i+1)) << endl;
	}

	int cnt = 1;
	set<int> st;
	for (int i=1; i<=n; i++){
		st.insert(i);
	}

	for (int i=n+1; i<=edge; i++) {
		int p = *st.begin();
		st.erase(st.begin());
		int q = *(++st.begin());
		st.erase(++st.begin());
		cout << p << ' ' << q << endl;
	}
	return 0;
}
