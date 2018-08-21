#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a;
int n,m;

bool check(){
	int num = 0;
	for (int i=0; i<n*m; i++){
	    for (int j=i; j<; j++){

	    }
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int ans = 0;
		cin>>n>>m;

		for (int i=0; i<n*m; i++){
			a.push_back((i+1));
		}

		while(next_permutation(a.begin(),a.end())){
			if(check())ans++;
		}
	}
	return 0;
}
