// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int ans[11][11];
int mn[11][11][11][11];

int getmn(int a, int b, int from, int to) {
	vector<int> lt, rt;

	int tp = from;
	while(true){
		tp += a;
		tp %= 10;
		bool f = 0;
		for (int i=0; i<lt.size(); i++){
			if (lt[i] == tp) f = 1;
		}
		if (!f) lt.push_back(tp);
		else break;
	}

	tp = from;
	while(true){
		tp += b;
		tp %= 10;
		bool f = 0;
		for (int i=0; i<rt.size(); i++){
			if (rt[i] == tp) f = 1;
		}
		if (!f) rt.push_back(tp);
		else break;
	}

	int mn = 1e9;
	for (int i=0; i<lt.size(); i++){
		if (lt[i] == to) {
			mn = min(mn,i);
		}
	}
	for (int i=0; i<rt.size(); i++) {
		if (rt[i] == to) {
			mn = min(mn,i);
		}
	}

	for (int i=0; i<lt.size(); i++){
	    for (int j=0; j<rt.size(); j++){
			if ((lt[i]+rt[j]-from+10)%10 == to) {
				mn = min(i+j+1,mn);
			}
	    }
	}
	if (mn == 1e9) return -1;
	else return mn;
}

void init() {
	int count = 10;
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			// cout << i << '-' << j << endl;
			for (size_t k = 0; k < count; k++) {
				for (size_t kk = 0; kk < count; kk++) {
					mn[i][j][k][kk] = getmn(i,j,k,kk);
					// cout << mn[i][j][k][kk] << (kk==9?'\n':' ');
				}
			}
			// cout << "---" << endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	string s;
	cin >> s;
	int count = 10;
	for (size_t lt = 0; lt < count; lt++) {
		for (size_t rt = 0; rt < count; rt++) {
			bool can = 1;
			for (int i=1; i<s.size(); i++){
			    if (i == 0) {
					int add = mn[lt][rt][0][s[i]-'0'];
					if (add == -1) {can = 0;break;}
					else ans[lt][rt] += add;
				}
				else {
					int add = mn[lt][rt][s[i-1]-'0'][s[i]-'0'];
					// if (lt == 0 && rt == 1) cout<<"add = "<<add<<endl;
					if (add == -1) {can = 0;break;}
					else ans[lt][rt] += add;
				}
			}
			if (!can) ans[lt][rt] = -1;
		}
	}
	for (int i=0; i<10; i++){
	    for (int j=0; j<10; j++){
			cout << ans[i][j] << (j==9?'\n':' ');
	    }
	}
	return 0;
}
