#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=2; i<=(1<<25); i*=2){
		int ans = 0;
		i--;
		cout << i << ":   ";
	    for (int j=1; j<=i-1; j++){
			ans = max(ans, __gcd((i&j),(i^j)));
	    }
		i++;
		cout << ans << endl;
	}
	return 0;
}
