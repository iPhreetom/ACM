#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int mp[25][25];
int n,m,k;
int cnt[25][25];
int ans = 0;

void bfs(int x,int y){
	if(x+1 < n){
		bfs(x+1,n);

	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mp[i][j];
		}
	}
	cnt[0][0]=1;
	bfs(0,0);

	return 0;
}
