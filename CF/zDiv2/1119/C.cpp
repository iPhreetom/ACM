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
			if(a[i][j])v++;
		}
	}

	int num = 0;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> b[i][j];
			if(b[i][j])u++;
			if(b[i][j] != a[i][j])num++;
		}
	}

	int a2 = ((n*m - u)-u);
	int b2 = ((n*m - v)-v);
	// a-b
	cout<<"u = "<<u<<endl;
	cout<<"v = "<<v<<endl;
	cout<<"n*m = "<<n*m<<endl;
	cout<<"num = "<<num<<endl;
	if(abs(a2-b2) % 2 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
