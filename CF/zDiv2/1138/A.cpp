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

	vector<int> v(n, 0);
	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	vector<int> p;
	int cnt = 1;
	v.push_back(3);
	for (int i=1; i<n+1; i++){
	    if(v[i] != v[i-1]) {
			p.push_back(cnt);
			cnt = 1;
		}
		else cnt++;
	}


	int ans = 0;
	p.push_back(0);
	for (int i=1; i<p.size(); i++){
		ans = max(ans, 2*min(p[i],p[i-1]));
	}
	cout << ans << endl;
	return 0;
}
