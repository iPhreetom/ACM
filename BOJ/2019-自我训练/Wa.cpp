// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// int n, m;
	// cin >> n >> m;
	// vector<string> v;
	// vector<int> book(n,0);
	// for (int i=0; i<n; i++){
	// 	string str;
	// 	cin >> str;
	// 	v.push_back(str);
	// }
	//
	// for (int i=0; i<m; i++){
	// 	string str;
	// 	cin >> str;
	// 	bool f = 0;
	// 	for (int j=0; j<v.size(); j++){
	// 		if (v[j] == str && book[j] == 0) {
	// 			book[j] = 1;
	// 			f = 1;
	// 			cout << "YES\n";
	// 			break;
	// 		}
	// 	}
	// 	if (!f) cout << "NO\n";
	// }
	int ans = 0;
	for (int i=0; i<3000000000; i++){
		ans ^= i;
	}
	cout << ans << endl;
	return 0;
}
