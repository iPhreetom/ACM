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
	vector<int> a(n);
	int cnt = 0;
	int cnt2 = 0;
	for (int i=0; i<n; i++){
	    cin >> a[i];
		if(a[i] > 0) cnt++;
		if(a[i] < 0) cnt2++;
	}
	if(cnt >= (n+1)/2) {
		cout << 1 << endl;
	}
	else {
		if(cnt2 >= (n+1)/2) {
			cout << -1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
