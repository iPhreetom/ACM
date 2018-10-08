// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0; i<k; i++){
		int t;
		cin>>t;
		a[t]++;
	}
	int dif=0;
	int now=a[1];
	vector<int> lis;
	for (int i=1; i<=n; i++){
		if(now != a[i]){
			dif++;
			lis.push_back(i);
		}
	}
	if(dif == n-1){
		// retry
		now = a[2];
		dif = 0;

		lis.clear();
		for (int i=1; i<=n; i++){
			if(now != a[i]){
				dif++;
				lis.push_back(i);
			}
		}

		
	}
	else{

	}

	return 0;
}
