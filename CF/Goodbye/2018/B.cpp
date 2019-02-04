// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> c;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	for (int i=1; i<=n; i++){
		int x,y;
		cin>>x>>y;
		c.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	sort(c.rbegin(),c.rend());
	cout<<v[0].first+c[0].first<<' '<<v[0].second+c[0].second<<endl;
	return 0;
}
