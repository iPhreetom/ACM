// fyt
#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;

map<int,set<pair<int,int>>> mp;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n = 1e3;
	for (int i=1; i<=n; i++){
	    for (int j=i; j<=n; j++){
			mp[i*j/__gcd(i,j)].insert(make_pair(i,j));
	    }
	}
	int num = 0;
	for (int i=1; i<=n; i++){
	    for (int j=i; j<=n; j++){
			num += mp[i].size();
	    }
	}
	cout<<"num = "<<num<<endl;
	return 0;
}
