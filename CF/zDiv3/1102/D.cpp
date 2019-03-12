#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int cnt[23];
int t[4][4];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++){
		cnt[s[i]-'0']++;
	}
	for (int i=0; i<3; i++){
		if(cnt[i] > n/3) {
			if(cnt[(i+1)%3] < n/3) {
				t[i][(i+1)%3] = min(cnt[i]-n/3,n/3-cnt[(i+1)%3]);
				cnt[i] -= t[i][(i+1)%3];
				cnt[(i+1)%3] += t[i][(i+1)%3];
			}
			if(cnt[(i+2)%3] < n/3) {
				t[i][(i+2)%3] = min(cnt[i]-n/3,n/3-cnt[(i+2)%3]);
				cnt[i] -= t[i][(i+2)%3];
				cnt[(i+2)%3] += t[i][(i+2)%3];
			}
		}
	}

	for (int i=2; i>=1; i--){
	    for (int j=0; j<3; j++){
	        if(t[i][j]){
				if(i > j) {
					for (int ii=0; ii<s.size() && t[i][j]; ii++){
						if((s[ii] - '0') == i){
							s[ii] = '0' + j;
							t[i][j]--;
						}
					}
				}
				else {
					for (int ii=n-1; ii>=0 && t[i][j]; ii--){
						if((s[ii] - '0') == i){
							s[ii] = '0' + j;
							t[i][j]--;
						}
					}
				}
			}
	    }
	}
	for (int i=0; i<=0; i++){
		for (int j=2; j>=0; j--) {
			if(t[i][j]){
				if(i > j) {
					for (int ii=0; ii<s.size() && t[i][j]; ii++){
						if((s[ii] - '0') == i){
							s[ii] = '0' + j;
							t[i][j]--;
						}
					}
				}
				else {
					for (int ii=n-1; ii>=0 && t[i][j]; ii--){
						if((s[ii] - '0') == i){
							s[ii] = '0' + j;
							t[i][j]--;
						}
					}
				}
			}
		}
	}


	cout << s << endl;
	return 0;
}
