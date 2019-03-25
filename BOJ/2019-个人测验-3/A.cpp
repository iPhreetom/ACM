// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s;
	string l;
	string r;
	for (int i=0; i<m; i++){
		s.push_back('#');
	}
	for (int i=0; i<m-1; i++){
		l.push_back('.');
		r.push_back('.');
	}
	r.push_back('#');
	l.push_back('#');
	reverse(l.begin(),l.end());

	bool f = 1;
	for (int i=0; i<n; i++){
		if(i%2 == 0) {
			cout << s << endl;
		}
		else {
			if (f) {
				cout << r << endl;
			}
			else {
				cout << l << endl;
			}
			f = !f;
		}
	}
	return 0;
}
