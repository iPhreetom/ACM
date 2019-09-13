// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int pos[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		for (int i=1; i<=n; i++){
			cin >> a[i];
			pos[a[i]] = i;
		}

		for (int i=1; i<=n; i++){
			int ans = 1;

		}
	}
	return 0;
}
