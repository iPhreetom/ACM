#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

priority_queue<int,vector<int>,greater<int>> que;
vector<int> mp[800];
int n;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int t;
				cin>>t;
				mp[i].push_back(t);
			}
		}

		for(int i=0;i<n;i++){
			sort(mp[i].begin(),mp[i].end());
		}

		
	}
	return 0;
}
