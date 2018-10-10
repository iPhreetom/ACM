#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> mp[21234];
int d[21234];
bool vis[21234];

int dfs(int p){
	int cnt = 1;
	for (int i=0; i<mp[p].size(); i++){
		if(vis[ mp[p][i] ] == 0){
			vis[ mp[p][i] ] = 1;
			cnt += dfs(mp[p][i]);
		}
	}
	return d[p] = cnt;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		mp[v].push_back(u);
		mp[u].push_back(v);
	}

	vis[0] = 1;
	dfs(0);

	int sum = -123;
	int big1 = -1 , big2 = -1;

	for (int i=0; i<=n; i++){
		int up = n+1 - d[i];
		int tot = up * (d[i]-1);
		vector<int> lis;
		for (int j=0; j<mp[i].size(); j++){
			if(d[mp[i][j]] < d[i]){
				lis.push_back(d[mp[i][j]]);
			}
		}

		for (int j=0; j<lis.size(); j++){
			for(int k = j+1;k<lis.size();k++){
				tot += lis[k] * lis[j];
			}
		}

		if(tot > sum){
			big1 = -1;
			big2 = -2;
			for (int j=0; j<lis.size(); j++){
				if(lis[j] > big1){
					big2 = big1;
					big1 = lis[j];
				}
				else if(lis[j] > big2){
					big2 = lis[j];
				}
			}
			if(up > big1){
				big1 = up;
				big2 = big1;
			}
			else if(up > big2){
				big2 = up;
			}
			sum = tot;
		}
		else if(tot == sum){
			for (int j=0; j<lis.size(); j++){
				if(lis[j] > big1){
					big2 = big1;
					big1 = lis[j];
				}
				else if(lis[j] > big2){
					big2 = lis[j];
				}
			}
			if(up > big1){
				big1 = up;
				big2 = big1;
			}
			else if(up > big2){
				big2 = up;
			}
		}
	}

	cout<<sum<<' ';
	cout<<sum - big1*big2<<endl;


	return 0;
}
