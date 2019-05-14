// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v(n+1);
	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	vector<int> ban(m, 0);
	int ans = 0;
	for (int i=0; i<m; i++){
		vector<string> temp;
		for (int index=0; index<n; index++) {
			string str;
			for (int pos=0; pos<=i; pos++) {
				if (!ban[pos])str.push_back(v[index][pos]);
			}
			temp.push_back(str);
		}
		if (!is_sorted(temp.begin(), temp.end())) {
			ban[i] = true;
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
