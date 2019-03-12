#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,m;
	cin >> n >> k >> m;
	vector<int> v;
	for (int i=1; i<=n; i++){
	    int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.rbegin(),v.rend());

	vector<int> pre;
	pre.push_back(v[0]);
	for (int i=1; i<n; i++){
		pre.push_back(v[i] + pre[i-1]);
	}

	double mx = 0;
	vector<int> ans(1123456,0);
	for (int i=max(0ll,n-m-1); i<n; i++){
		double sum = pre[i];
		int len = i+1;
		int res = m - (n-i-1);
		int mxop = len*k;
		sum += min(mxop,res);
		mx = max(mx, sum/len);
	}
	cout << fixed << setprecision(13) <<  mx << endl;
	return 0;
}
