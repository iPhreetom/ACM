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
	vector<int> v(n);
	vector<int> lis(n);
	for (int i=0; i<n; i++){
	    cin >> v[i];
	}
	for (int i=0; i<n; i++){
		cin >> lis[i];
	}

	if (lis[0] != 0) {
		bool f = 1;
		for (int i=1; i<n; i++){
			if (lis[i] != lis[i-1]+1) f = 0;
		}
		if (f) {
			cout << 0 << endl;
			return 0;
		}
	}

	int f = 0;
	if (lis[n-1] == 1) {
		vector<int> book(n+1,0);
		int now = 0;
		for (int i=0; i<n; i++){
			book[v[i]] = 1;
			book[1] = 1;
		}
		for (int i=2; i<=n; i++){
			if (book[i] == 0) {
				break;
			}
			if(i == n) {
				f = 1;
			}
			else {
				book[ lis[now] ] ++;
				now++;
			}
		}
	}
	else if (lis[n-1] != 0){
		int index = n-2;
		int be = 0;
		for (; index >= 0; index--) {
			if (lis[index] == lis[index+1]-1 && lis[index] != 0) {
				if (lis[index] == 1) {
					be = lis[n-1];
				}
				else continue;
			}
			else {
				break;
			}
		}
		if (be != 0) {
			vector<int> book(n+1,0);
			for (int i=0; i<v.size(); i++){
				book[v[i]] = 1;
			}
			for (int i=1; i<=be; i++){
				book[i] = 1;
			}
			int now = 0;
			for (int i=be+1;i<=n;i++) {
				if (book[i] == 0) {
					break;
				}
				if(i == n) {
					f = be;
				}
				else {
					book[ lis[now] ] ++;
					now++;
				}
			}
		}
	}

	int mx = 0;
	if (f == 0) {
		for (int i=0; i<n; i++){
			int val = lis[i];
			if (val != 0) mx = max(mx, i-val+2);
		}
		cout << n + mx << endl;
	}
	else {
		cout << n-f << endl;
	}
	return 0;
}
