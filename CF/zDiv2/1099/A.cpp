#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int w,d;
	cin >> w >> d;
	int u1,d1;
	cin >> u1 >> d1;
	int u2,d2;
	cin >> u2 >> d2;

	if(d2 > d1) {
		swap(d2,d1);
		swap(u2,u1);
	}

	for (int i=d; i>=0; i--){
		w += i;
		if(d2 == i) {
			w -= min(w,u2);
		}
		if(d1 == i) {
			w -= min(w,u1);
		}
	}
	cout << w << endl;
	return 0;
}
