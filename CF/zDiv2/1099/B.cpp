#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int l = 1;
	int r = 1;
	while(l*r < n) {
		if(l <= r) l ++;
		else r ++;
	}
	cout << r + l << endl;
	return 0;
}
