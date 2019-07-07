// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int l;
	cin >> l;

	int x = 0;
	int mx = pow(2,32)-1;
	stack<int> st;
	int base = 1;
	int cnt = 0;

	for (int i=1; i<=l; i++){
		string s;
		cin >> s;
		if (s == "end") {
			if (cnt > 0) cnt--;
			else {
				base /= st.top();
			}
			st.pop();
		}
		else if (s == "add") {
			if (cnt>0) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
			else {
				x += base;
			}
		}
		else { // for
			int t;
			cin >> t;
			if (base*t > mx || cnt > 0) {
				cnt++;
			}
			else {
				base *= t;
			}
			st.push(t);
		}

		if (x > mx) {
			cout << "OVERFLOW!!!" << endl;
			return 0;
		}
	}
	cout << x << endl;
	return 0;
}
