// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,sx,sy,ex,ey;
	cin >> t >> sx >> sy >> ex >> ey ;
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++){
		if(sx < ex) {
			if(s[i] == 'E') {
				sx++;
			}
		}

		if(sx > ex) {
			if(s[i] == 'W') {
				sx--;
			}
		}

		if(sy < ey) {
			if(s[i] == 'N') {
				sy++;
			}
		}

		if(sy > ey) {
			if(s[i] == 'S') {
				sy--;
			}
		}

		if(sx == ex && sy == ey) {
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
