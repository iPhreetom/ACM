// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[2123][2123];
int l[2123];
int r[2123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// 1 0 0 1 0 0
	// 0 1 1 0 0 1
	// 0 1 1 0 1 0
	// 9 0 0 9 0 0
	// 0 1 1 0 1 0
	// 0 1 1 0 0 1
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin>>a[i][j];
		}
	}
	vector<int> v;
	for (int i=0; i<10; i++){
		v.push_back(i);
	}

	for (int i=0; i<v.size(); i++){
		cout<<v[i]<<endl;
	}
	return 0;
}
