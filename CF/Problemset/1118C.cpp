#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	vector<int> v;
	map<int,int> mp;
	cin >> n;
	for (int i=1; i<=n*n; i++) {
		int t;
		cin >> t;
		mp[t]++;
	}


	int a[22][22];
	int cnt = 0;
	for (auto &index : mp) {
		if(index.second % 2 == 1) {
			cnt ++;
			index.second --;
			a[(n+1)/2][(n+1)/2] = index.first;
		}
	}
	if(cnt > 1) {
		cout << "NO" << endl;
		return 0;
	}


	for (int i=1; i<=(n+1)/2; i++) {
		for (int j=1; j<=(n+1)/2; j++) {
			// for (auto index : mp) {
			// 	cout << index.first << ' ' << index.second << endl;
			// }
			if((n&1) == 1) {
				// n is odd
				if (i == (n+1)/2) {
					if(j == (n+1)/2) {

					}
					else {
						bool ok = 0;
						for (auto &index : mp) {
							if(index.second != 0 && index.second%2 == 0 && index.second % 4 != 0) {
								ok = 1;
								index.second -= 2;
								a[i][j] = index.first;
								a[n-i+1][j] = index.first;
								a[i][n-j+1] = index.first;
								a[n-i+1][n-j+1] = index.first;
								break;
							}
						}
						if(!ok) {
							for (auto &index : mp) {
								if(index.second != 0 && index.second%2 == 0) {
									ok = 1;
									index.second -= 2;
									a[i][j] = index.first;
									a[n-i+1][j] = index.first;
									a[i][n-j+1] = index.first;
									a[n-i+1][n-j+1] = index.first;
									break;
								}
							}
						}
						if(!ok) {
							cout << "NO" << endl;
							return 0;
						}
					}
				}
				else {
					if(j == (n+1)/2) {
						bool ok = 0;
						for (auto &index : mp) {
							if(index.second != 0 && index.second%2 == 0 && index.second % 4 != 0) {
								ok = 1;
								index.second -= 2;
								a[i][j] = index.first;
								a[n-i+1][j] = index.first;
								a[i][n-j+1] = index.first;
								a[n-i+1][n-j+1] = index.first;
								break;
							}
						}
						if(!ok) {
							for (auto &index : mp) {
								if(index.second != 0 && index.second%2 == 0) {
									ok = 1;
									index.second -= 2;
									a[i][j] = index.first;
									a[n-i+1][j] = index.first;
									a[i][n-j+1] = index.first;
									a[n-i+1][n-j+1] = index.first;
									break;
								}
							}
						}
						if(!ok) {
							cout << "NO" << endl;
							return 0;
						}
					}
					else {
						bool ok = 0;
						for (auto &index : mp) {
							if(index.second != 0 && index.second >= 4) {
								ok = 1;
								index.second -= 4;
								a[i][j] = index.first;
								a[n-i+1][j] = index.first;
								a[i][n-j+1] = index.first;
								a[n-i+1][n-j+1] = index.first;
								break;
							}
						}
						if(!ok) {
							cout << "NO" << endl;
							return 0;
						}
					}
				}
			}
			else {
				// n is even
				bool ok = 0;
				for (auto &index : mp) {
					if(index.second != 0 && index.second%4 == 0) {
						ok = 1;
						index.second -= 4;
						a[i][j] = index.first;
						a[n-i+1][j] = index.first;
						a[i][n-j+1] = index.first;
						a[n-i+1][n-j+1] = index.first;
						break;
					}
				}
				if(!ok) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
