a#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<string> v(n);
	set<string> s;
	for (int i=0; i<n; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}

	int m;
	cin >> m;
	map<string,string> mp;
	map<string,int> ccnt;
	map<string,int> ncnt;

	bool ok = 1;
	bool can = 1;
	for (int i=0; i<m; i++) {
		string a,b,c;
		cin >> a >> b >> c;
		if(c == "correct") {
			if (s.count(a) != 0) {
				if(++ccnt[a] > 1)ok = 0;
				mp[a] = b;
			}
		}
		else {
			if (s.count(a) != 0) {
				if(++ncnt[a] > 1)ok = 0;
				mp[a] = b;
				can = 0;
			}
		}
	}

	if(ok) {
		for (int i=0; i<n; i++) {
			cout << mp[v[i]] << ' ';
		}
		cout << endl;
		if(can) {
			cout << "correct" << endl;
		}
		else {
			cout << "incorrect" << endl;
		}
		return 0;
	}

	vector<unsigned long long> dp1(n+1, 0);
	vector<unsigned long long> dp2(n+1, 0);

	dp1[0] = ccnt[v[0]];
	dp2[0] = ncnt[v[0]];

	for (int i=1; i<n; i++) {
		dp1[i] = dp1[i-1] * ccnt[v[i]];
		dp2[i] = (dp1[i-1]+dp2[i-1])*ncnt[v[i]] + dp2[i-1]*ccnt[v[i]];
	}

	cout << dp1[n-1] << " correct" << endl;
	cout << dp2[n-1] << " incorrect" << endl;

	return 0;
}
//
