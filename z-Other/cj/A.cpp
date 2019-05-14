#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

string ans;
bool findit = 0;
bool cant = 0;
int mx = 0;

char chose(char ch) {
	if (ch == 'R') {
		return 'P';
	}
	if (ch == 'P') {
		return 'S';
	}
	if (ch == 'S') {
		return 'R';
	}
	return '?';
}

void dfs(vector<string> &s, int index) {
	if (cant || findit) return;
	if (index == mx) {
		cant = 1;
		return ;
	}

	set<char> st;
	for (int i=0; i<s.size(); i++) {
		st.insert(s[i][index]);
	}

	if (st.size() == 3) {
		cant = 1;
		return ;
	}
	if (st.size() == 1) {
		ans.push_back(chose(*st.begin()));
		findit = 1;
		return ;
	}
	if (st.size() == 2) {
		vector<string> s1;
		vector<string> s2;
		auto ch = st.begin();
		auto pch = st.begin();
		ch++;
		for (int i=0; i<s.size(); i++) {
			cout << "s[i] = " << s[i] << endl;
			if (s[i][index] == *ch) {
				s1.push_back(s[i]);
			}
			else {
				s2.push_back(s[i]);
			}
		}
		cout << endl;
		if (chose(*ch) != *pch) {
			ans.push_back(*ch);
			dfs(s1, index+1);
		}
		else {
			ans.push_back(*pch);
			dfs(s2, index+1);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<string> s;
		mx = 0;
		for (int i=0; i<n; i++) {
			string tp;
			cin >> tp;
			s.push_back(tp);
			mx = max(mx,(int)tp.size());
		}
		for (int i=0; i<n; i++) {
			int index = 0;
			while (s[i].size() != mx) {
				s[i].push_back(s[i][index]);
				index++;
			}
		}
		sort(s.begin(),s.end());

		ans.clear();
		findit = 0;
		cant = 0;
		dfs(s, 0);

		if (findit && !cant) {
			cout << ans << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
