// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int mp[2123][2123];
int prehb[2123][2123];
int prehs[2123][2123];
int prelb[2123][2123];
int prels[2123][2123];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;

	for (int i=1; i<=n; i++){
		map<int,int> lis;
		for (int j=1; j<=m; j++){
			cin >> mp[i][j];
			lis [mp[i][j]] = 1;
		}
		int cnt = 0;
		for (auto &j : lis) {
			j.second = ++cnt;
		}

		int len = lis.size();
		// cout<<"len = "<<len<<endl;
		for (int j=1; j<=m; j++){
			// cout<<"lis[mp[i][j]] = "<<lis[mp[i][j]]<<endl;
			prehb[i][j] = len - lis[mp[i][j]];
			prehs[i][j] = lis[mp[i][j]] -1 ;
		}
	}

	for (int i=1; i<=m; i++){
		map<int,int> lis;
		for (int j=1; j<=n; j++){
			lis [ mp[j][i] ] = 1;
		}

		int cnt = 0;
		for (auto &j : lis) {
			j.second = ++cnt;
		}

		int len = lis.size();
		for (int j=1; j<=n; j++){
			prelb[j][i] = len - lis[mp[j][i]];
			prels[j][i] = lis[mp[j][i]] -1 ;
		}
	}

	// cout << endl;
	// for (int i=1; i<=n; i++){
	// 	for (int j=1; j<=m; j++){
	// 		cout << prehb[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// for (int i=1; i<=n; i++){
	// 	for (int j=1; j<=m; j++){
	// 		cout << prehs[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			int base = max(prehs[i][j], prels[i][j]);
			int big = max(prehb[i][j], prelb[i][j]) + base + 1;
			cout << big << ' ';
		}
		cout << endl;
	}


	return 0;
}
