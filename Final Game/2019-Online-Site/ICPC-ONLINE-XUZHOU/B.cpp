// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	vector<int> v;
	vector<pair<int,int>> que;
	while(q--){
		int z,x;
		cin >> z >> x;
		v.push_back(x);
		que.push_back(make_pair(z,x));
	}
	sort(v.begin(),v.end());

	return 0;
}
