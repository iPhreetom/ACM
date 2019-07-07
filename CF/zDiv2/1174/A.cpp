// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i=1; i<=n*2; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int ans = 0;
	int num = 0;
	for (int i=0; i<n; i++){
	    ans += v[i];
	}
	for (int i=n; i<2*n; i++){
		num += v[i];
	}
	if (ans == num) {
		cout << -1 << endl;
	}
	else {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
