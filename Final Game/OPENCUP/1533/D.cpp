// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int snz[5123];
int sno[5123];
int tnz[5123];
int tno[5123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s,t;
	cin >> s >> t;
	for (int i=s.size()-1; i>=0; i--) {
		snz[i] = snz[i+1];
		sno[i] = sno[i+1];
		if (s[i] == '0') snz[i]++;
		else sno[i]++;
	}
	for (int i=t.size()-1; i>=0; i--) {
		tnz[i] = tnz[i+1];
		tno[i] = tno[i+1];
		if (t[i] == '0') tnz[i]++;
		else tno[i]++;
	}

	int ansz = 1e9, anso = 1e9;
	for (int i=0; i<s.size(); i++){

	}
	return 0;
}
