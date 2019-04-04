#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n = 59084709587505LL;
	int cnt = 0;
	for (int i=0; i<log(n)/log(3); i++) {
	    for (int j=0; j<log(n)/log(5); j++) {
	        for (int k=0; k<log(n)/log(7); k++) {
				if(pow(3,i)+pow(5,j)+pow(7,k) < n)cnt++;
			}
	    }
	}
	cout << cnt << endl;
	return 0;
}
