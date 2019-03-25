// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=min(n,m); i<=max(n,m); i++){
		cout << i+1 << endl;
	}
	return 0;
}
