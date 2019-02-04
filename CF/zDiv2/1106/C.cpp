#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> v;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for (int i=0; i<v.size()/2; i++){
		sum += (v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
	}
	cout << sum << endl;
	return 0;
}
