// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> a;
vector<pair<int,int> > b;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,s,k;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	for (int i=0; i<m; i++){
		int x,y;
		cin>>x>>y;
		b.push_back(make_pair(x,y));
	}

	return 0;
}
