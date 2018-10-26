// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[212345];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;
	cin>>n>>t;

	for (int i=1; i<=n; i++){
		cin>>a[i];
	}

	int ans = 0;
	while(1){

		bool can = 0;
		int sum = 0;
		int cnt = 0;

		for (int i=1; i<=n; i++){
			if(a[i] <= t){
				t -= a[i];
				ans++;
				cnt++;
				sum += a[i];
				can = 1;
			}
		}

		if(can == 0)break;

		if(t >= sum){
			int f = t / sum;
			t -= f*sum;
			ans += cnt*f;
		}


	}
	cout<<ans<<endl;
	return 0;
}
