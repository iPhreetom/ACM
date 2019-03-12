// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int w1,h1,w2,h2;
	cin >> w1 >> h1 >> w2 >> h2;
	int ans = 0;
	// ans += h1*2 + 2;
	if(w1 == w2) {
		ans = (h1+h2)*2 + w1*2 + 4;
	}
	else if(w1 > w2) {
		ans = 4 + h1*2 + w1*2 + (h2-1)*2 + 2;
	}
	else {
		swap(w1,w2);
		swap(h1,h2);
		ans = 4 + h1*2 + w1*2 + (h2-1)*2 + 2;
	}
	cout << ans << endl;

	return 0;
}
