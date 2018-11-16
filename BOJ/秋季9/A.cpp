// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,s;
	cin>>n>>s;
	int ans = -1;
	for (int i=0; i<n; i++){
		int x,y;

		cin>>x>>y;
		if((s > x) || (s == x && y == 0)){
			ans = max(ans,(100-y)%100);
		}

	}
	cout<<ans<<endl;
	return 0;
}
