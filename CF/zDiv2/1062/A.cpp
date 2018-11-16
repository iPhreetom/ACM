// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int a[2123];

	int ans = 0;
	int cnt = 1;
	a[0] = 11231231;

	for (int i=1; i<=n+1; i++){
		if(i != n+1)cin>>a[i];

		if(a[i] == a[i-1]+1){
			cnt++;
		}

		else{
			if(a[i-1] == i-1){
				ans = max(ans,i-2);
			}
			else if(a[i-1] == 1000){
				ans = max(ans,cnt-1);
			}
			else if(cnt >= 3){
				ans = max(ans,cnt-2);
			}
			cnt = 1;
		}

	}
	cout<<ans<<endl;
	return 0;
}
// 1
