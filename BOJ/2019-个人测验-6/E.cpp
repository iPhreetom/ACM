#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	int ans = 0;
	while(n--){
		int a,b,c;
		cin >> a >> b >> c;
		if ( ((x1*a + b*y1 + c)^(x2*a+b*y2+c)) < 0 ) ans++;
	}
	cout << ans << endl;
	return 0;
}
