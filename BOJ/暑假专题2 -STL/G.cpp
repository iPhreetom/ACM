#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> a(112345);
map<int,vector<int>> mp;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while(cin>>n>>m){
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]].push_back(i);
		}

		int k,v;
		for(int i=0;i<m;i++){
			cin>>k>>v;
			if(mp.count(v)==0 || mp[v].size() < k){
				cout<<0<<'\n';
			}else{
				cout<<mp[v][k-1]<<'\n';
			}
		}
	}
	return 0;
}
