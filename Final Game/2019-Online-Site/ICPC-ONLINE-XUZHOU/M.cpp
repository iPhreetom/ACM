// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int lis[1123456][26];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s,t;
	cin >> s >> t;

	string ans;
	string ansb;
	for (int i=0; i<s.size(); i++){
		if (s[i] > t[0]) {
			ansb = s.substr(i);
			break;
		}
	}

	int index = 0;
	bool f = 0;
	for (int i=0; i<s.size(); i++){
		if (index == t.size()) {
			ans += s.substr(i);
			f = 1;
			break;
		}

		if (s[i] >= t[index]) {
			if (s[i] == t[index]) {
				ans.push_back(t[index]);
			}
			else { // s[i] > t[index]
				f = 1;
				ans += s.substr(i);
				break;
			}
			index++;
		}
	}

	if ((ans.empty() && ansb.empty())) {
		cout << -1 << endl;
	}
	else if (!f && ansb.empty()){
		cout << -1 << endl;
	}
	else {
		if (f) cout << max(ansb.size(),ans.size()) << endl;
		else cout << ansb.size() << endl;
	}
	return 0;
}
