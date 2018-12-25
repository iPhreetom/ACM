// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n,k;
int a[2123456];

inline bool check(int k){
	int sum = 0;
	int res = k;
	for (int i=1; i<=n; i++){
		if(res <= a[i]){
			res -= a[i];
		}
		else{

		}
	}
	if(){
		
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;

	for (int i=1; i<=n; i++){
		cin>>a[i];
	}

	int l = 1;
	int r = 1e10;
	while(l+1 < r){
		int mid = l + (r-l)/2;
		if(check(mid))l = mid;
		else r = mid;
	}

	return 0;
}
