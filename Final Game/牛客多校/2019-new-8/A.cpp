	// fyt
	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	#define endl '\n'
	using namespace std;

	vector<int> a[212345];

	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i=0; i<212345; i++){
			a[i].push_back(0);
		}
		for (int i=0; i<n; i++){
			cin >> v[i];
			a[v[i]].push_back(i+1);
		}
		for (int i=0; i<212345; i++){
			a[i].push_back(n+1);
		}

		int sum = 0;
		for (int i=0; i<212345; i++){
			if (a[i].size()>2) {
				for (int j=1; j<a[i].size()-1; j++){
					sum += (a[i][j])*(a[i][j+1]-a[i][j]);
				}
			}
		}
		cout << sum << endl;
		return 0;
	}
