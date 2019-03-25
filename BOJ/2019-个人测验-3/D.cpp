// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

inline bool check(char &ch) {
	if(ch == 'I' || ch == 'E' || ch == 'A' || ch == 'O' || ch == 'U' || ch == 'Y')return 1;
	else return 0;
}
double fa[512345];
double pre[512345];
double suf[512345];
double val[512345];


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int len = s.size();
	for (int i=1; i<512345; i++){
		fa[i] = fa[i-1] + (1.0/(double)i);
	}

	for (int i=1; i<=len; i++){
		pre[i] = fa[i] + pre[i-1];
		suf[i] = suf[i-1] + fa[len-i+1];
	}

	for (int i=1; i<=len; i++){
		val[i] = suf[i] - pre[i-1];
	}

	double ans = 0;

	for (int i=0; i<s.size(); i++){
		if(check(s[i])) {
			ans += val[i+1];
		}
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
