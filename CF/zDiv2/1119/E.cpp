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
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;

	for (int i=0; i<n; i++){
	    cin >> a[i];
		que.push(make_pair(i,a[i]));
	}

	int ans = 0;
	int index = n-1;
	for (int i=0; i<=index; i++){
		int val = que.top().second;
		// if()
	}
	cout << ans << endl;

	return 0;
}
