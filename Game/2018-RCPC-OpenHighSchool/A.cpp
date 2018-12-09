// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int> > v;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		int m;
		cin>>m;
		int mx = 0;
		for (int j=1; j<=m; j++){
			int t;
			cin>>t;
			mx = max(mx,t);
		}
		v.push_back(make_pair(mx,m));
	}

	int ans = 0;
	sort(v.begin(),v.end());
	for (int i=1; i<v.size(); i++){
		if(v[i].first != v[i-1].first){
			ans += (v[i].first-v[i-1].first)*v[i-1].second;
		}
		v[i].second += v[i-1].second;
	}
	cout<<ans<<endl;
	return 0;
}
