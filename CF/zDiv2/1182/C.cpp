#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool check(char ch) {
	if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u') {
		return 1;
	}
	else return 0;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	typedef pair<int,pair<char,string>> pii;
	vector<pii> v;
	for (int i=0; i<n; i++) {
		int cnt = 0;
		string s;
		cin >> s;
		char ch;
		for (int i=0; i<s.size(); i++) {
			if (check(s[i])) {
				ch = s[i];
				cnt++;
			}
		}
		v.push_back(make_pair(cnt,make_pair(ch,s)));
	}
	sort(v.rbegin(),v.rend());

	int sum = 0;
	vector<pii> res;
	queue<pair<pii,pii>> cp;
	vector<bool> vis(n);

	for (int i=0; i<v.size()-1; i++) {
		if (v[i].first == v[i+1].first) {
			if (v[i].second.first == v[i+1].second.first) {
				vis[i] = 1;
				vis[i+1] = 1;
				cp.push(make_pair(v[i],v[i+1]));
				i++;
			}
			else {
				res.push_back(v[i]);
			}
		}
		else {
			res.push_back(v[i]);
		}
	}
	if (!vis[v.size()-1]) {
		res.push_back(v[v.size()-1]);
	}

	int index = 0;
	vector<pair<pii,pii>> fp;
	vector<pair<pii,pii>> sp;
	while (!cp.empty()) {
		if (index >= ((int)res.size())-1) {
			pair<pii,pii> tp = cp.front();
			cp.pop();
			if (!cp.empty()) {
				fp.push_back(tp);
				sp.push_back(cp.front());
				cp.pop();
			}
		}
		else {
			for (;index<((int)res.size())-1;) {
				if (res[index].first == res[index+1].first) {
					fp.push_back(make_pair(res[index],res[index+1]));
					sp.push_back(cp.front());
					cp.pop();
					index++;
					index++;
					break;
				}
				else {
					index++;
				}
			}
		}
	}

	cout << fp.size() << endl;
	for (int i=0; i<fp.size(); i++) {
		cout << fp[i].first.second.second << ' ' << sp[i].first.second.second << endl;
		cout << fp[i].second.second.second << ' ' << sp[i].second.second.second << endl;
	}
	return 0;
}
