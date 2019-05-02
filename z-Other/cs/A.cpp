#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	for (int cs=1; cs<=t; cs++){
		int n,m;
		cin >> n >> m;
		if(max(n,m)!=5){
			cout << "Case #" << cs << ": ";
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			if(min(n,m) == 3){
				cout << "Case #" << cs << ": ";
				cout << "IMPOSSIBLE" << endl;
			}
			else {
				n = min(n,m);
				cout << "Case #" << cs << ": ";
				cout << "POSSIBLE" << endl;
				if(n == 2) {
					cout << "2 3" << endl;
					cout << "1 1" << endl;
					cout << "2 4" << endl;
					cout << "1 2" << endl;
					cout << "2 5" << endl;
					cout << "1 3" << endl;
					cout << "2 1" << endl;
					cout << "1 5" << endl;
					cout << "2 2" << endl;
					cout << "1 4" << endl;
				}
				if(n == 4){
					cout << "2 3" << endl;
					cout << "1 1" << endl;
					cout << "2 4" << endl;
					cout << "1 2" << endl;
					cout << "2 5" << endl;
					cout << "1 3" << endl;
					cout << "2 1" << endl;
					cout << "1 5" << endl;
					cout << "2 2" << endl;
					cout << "1 4" << endl;
					//
					cout << "4 3" << endl;
					cout << "3 1" << endl;
					cout << "4 4" << endl;
					cout << "3 2" << endl;
					cout << "4 5" << endl;
					cout << "3 3" << endl;
					cout << "4 1" << endl;
					cout << "3 5" << endl;
					cout << "4 2" << endl;
					cout << "3 4" << endl;
				}
				if(n == 5) {
					cout << "1 1" << endl;
					cout << "2 3" << endl;
					cout << "1 5" << endl;
					cout << "2 1" << endl;
					cout << "1 3" << endl;
					cout << "2 5" << endl;
					cout << "1 2" << endl;
					cout << "2 4" << endl;
					cout << "3 1" << endl;
					cout << "1 4" << endl;
					cout << "2 2" << endl;
					cout << "3 4" << endl;
					cout << "4 1" << endl;
					cout << "3 3" << endl;
					cout << "4 5" << endl;
					cout << "5 1" << endl;
					cout << "4 3" << endl;
					cout << "5 5" << endl;
					cout << "4 2" << endl;
					cout << "5 4" << endl;
					cout << "3 5" << endl;
					cout << "5 2" << endl;
					cout << "4 4" << endl;
					cout << "3 2" << endl;
					cout << "5 3" << endl;
				}
			}
		}
	}
	return 0;
}
