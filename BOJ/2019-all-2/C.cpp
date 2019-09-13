// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;
int n,m;
string s;
bool cant = 0;
char final;

inline bool check() {
	for (int i=1; i<s.size(); i++){
		if (s[i] == s[i-1]) return false;
		if (i >= 2 && s[i] == s[i-2]) return false;
	}
	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> s;

	final = 'a'+m-1;
	int all = final*n;
	if (n == 1) {
		if (s.back() == final) cout << "NO" << endl;
		else cout << (char)(s[0]+1) << endl;
		return 0;
	}

	reverse(s.begin(),s.end());
	bool f = 0;
	int sz = s.size();


	// add one
	int up = 1;
	for (int i=0; i<sz; i++){
		if (up) {
			if (s[i] == final) {
				if (i == sz-1) cant = 1;
				s[i] = 'a';
				up = 1;
			}
			else {
				s[i]++;
				break;
			}
		}
	}
	if (check()){
		f = 1;
	}

	while (!f && !cant) {
		int up = 0;
		int bro = 0;
		for (int i=0; i<sz; i++){
			if (bro >= m) {cant = 1;break;}
			if (up) {
				if (s[i] == final) {
					if (i == sz-1) {cant = 1;break;}
					s[i] = 'a';
					up = 1;
					bro = 0;
				}
				else {
					s[i]++;
					if (i<sz-1 && s[i] == s[i+1]) up = 1, i--,bro++;
					else if (i<sz-2 && s[i] == s[i+2]) up = 1, i--, bro++;
					else break;
				}
			}
		}

		if (cant) break;
		if (check()){
			f = 1;
			break;
		}
	}

	if (f && !cant) {
		reverse(s.begin(),s.end());
		cout << s << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
