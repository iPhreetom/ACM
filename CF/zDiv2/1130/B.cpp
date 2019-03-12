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
	vector<pair<int,int>> a(n*2);
	for (int i=0; i<n*2; i++){
	    int t; cin >> t;
		a[i] = make_pair(t,i);
	}
	sort(a.begin(),a.end());
	int sum = 0;
	int now = 0;
	for (int i=0; i<2*n; i+=2){
		sum += abs(a[i].second-now);
		now = a[i].second;
	}
	now = 0;
	for (int i=1; i<2*n; i+=2){
		sum += abs(a[i].second-now);
		now = a[i].second;
	}
	cout << sum << endl;

	return 0;
}
