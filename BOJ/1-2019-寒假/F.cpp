// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int dp[212345];
int n;
int c;
multiset<int> s;
multiset<int> mxs;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>c;
	int sum = 0;
	int cnt = 0;
	int mn = 0;

	for (int i=1; i<=n; i++){
		cin>>a[i];
		sum += a[i];
		s.insert(a[i]);
		cnt++;
		if(cnt >= c){
			mn = *s.begin();
			dp[i] = mn;
			s.erase(s.find(a[i-c+1]));
			cnt--;
		}
	}
	if(c == 1) {
		cout<<0<<endl;
		return 0;
	}

	for (int i=1; i<=c-1; i++){
		mxs.insert(dp[i]);
	}

	for(int i=c; i<=n; i++) {
		int mx = 0;
		auto index = mxs.rbegin();
		mx = *index;

		dp[i] = max(dp[i]+dp[i-c],mx);

		mxs.erase(mxs.find(dp[i-c+1]));
		mxs.insert(dp[i]);
	}
	cout<<sum-dp[n]<<endl;
	return 0;
}
