// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int toint (string &s) {
	int ret = 0;
	int len = s.size()-1;
	for (int i=0; i<s.size(); i++){
		ret += (s[i]-'0')*pow(10,len);
		len--;
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int cnt = 1;
	bool ok = 1;
	bool first = 0;
	for (int i=1; i<=n; i++){
		string s;
		cin >> s;
		if (s != "mumble") {
			int now = toint(s);
			if (now != cnt) {
				ok = 0;
			}
		}
		cnt++;
	}
	if (ok) {
		cout << "makes sense" << endl;
	}
	else {
		cout << "something is fishy" << endl;
	}
	return 0;
}
