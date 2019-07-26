// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		int len = a.back();
		a.pop_back();
		len = min(len,a.back());
		a.pop_back();
		int ans = 0;
		ans = min(len-1,(long long)a.size());
		cout << ans << endl;
	}
	return 0;
}
