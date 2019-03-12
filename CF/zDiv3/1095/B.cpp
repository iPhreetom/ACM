#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	vector<int> v;
	cin >> n;
	for (int i=0; i<n; i++){
	    int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(),v.end());

	if(n == 2){
		cout << 0 << endl;
		return 0;
	}

	cout << min(abs(v[n-2] - v[0]),abs(v.back()-v[1])) << endl;
	return 0;
}
