// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool a[512][512];
bool b[512][512];


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int u = 0;
	int v = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> b[i][j];
		}
	}

	for (int i=1; i<=n; i++){
		int hang1 = 0;
		int hang2 = 0;
		for (int j=1; j<=m; j++){
			if(a[i][j])hang1++;
			if(b[i][j])hang2++;
		}
		if(abs(hang1-hang2)%2 != 0) {
			cout << "NO" << endl;
			return 0;
		}
	}

	for (int i=1; i<=m; i++){
		int lie1 = 0;
		int lie2 = 0;
		for (int j=1; j<=n; j++){
			if(a[j][i])lie1++;
			if(b[j][i])lie2++;
		}
		if(abs(lie1-lie2)%2 != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
