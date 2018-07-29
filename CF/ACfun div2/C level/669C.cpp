#include<bits/stdc++.h>
#define int long long
using namespace std;

int mp[105][105];
vector<pair<int,int> > vec;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>m>>n>>q;

	for(int i=0;i<q;i++){
		int t;
		cin>>t;
		if(t == 3){
			int it,jt,v;
			cin>>it>>jt>>v;

			for(int j=vec.size()-1;!vec.empty()&&j>=0;j--){
				// cout<<vec[i].second<<endl;
				int i = j;
				if(vec[i].first == 1){
					if(vec[i].second == it){
						jt += 1;
						// cout<<jt<<endl;
						if(jt == n+1)jt = 1;
					}
				}
			 	if(vec[i].first == 2){
					if(vec[i].second == jt){
						it += 1;
						if(it == m+1)it = 1;
					}
				}
			}
			mp[it][jt]=v;
			// cout<<it<<' '<<jt<<endl;
		}
		else{
			int v;
			cin>>v;
			vec.push_back(make_pair(t,v));
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<mp[i][j]<<' ';
		}cout<<endl;
	}

	return 0;
}
