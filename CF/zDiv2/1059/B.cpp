// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n,m;
string mp[1123];


bool f(int x,int y){
	for (int i=x; i<x+3; i++){
		for (int j=y; j<y+3; j++){
			if(i < 0 || j < 0 || i >= n || j >= m ){
				return 0;
			}
			if(i == x+1 && j == y+1)continue;
			if(mp[i][j] != '#')return 0;
		}
	}
	return 1;
}

bool check(int x,int y){
	bool ok = 0;
	for(int i=-2;i<=0;i++){
		for(int j=-2;j<=0;j++){
			if(i == -1 && j == -1)continue;
			if(f(x+i,y+j) == 1){
				return 1;
			}
		}
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;

	for (int i=0; i<n; i++){
		cin>>mp[i];
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if(mp[i][j] == '#' && check(i,j) == 0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
