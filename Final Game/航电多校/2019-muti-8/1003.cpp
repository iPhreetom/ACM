// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for (int i=1; i<=1000; i++){
		int ans = -1;
		for (int j=i; j>=0; j--){
			string t = to_string(j);
			int cnt = 0;

			if (cnt == j) {
				ans = cnt;
			}
		}
		cout<<"i = "<<i<<endl;
		cout << ans << endl;
	}
	return 0;
}
