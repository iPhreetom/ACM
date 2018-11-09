#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define int long long
#define double long double
using namespace std;

string mp[40][40];
int l,r,c;
int ex,ey,ez;
int ans = -1;
bool vis[40][40][40];

struct node{
	int x,y,z;
	node(){};
	node(int x,int y,int z):x(x),y(y),z(z){};
};

inline void init(){
	ans = -1;
	memset(vis,0,sizeof(vis));
}

inline bool input(){
	cin>>l>>r>>c;
	if(l == 0 && r == 0 && c == 0)return 0;
	for (int i=0; i<l; i++){
		for (int j=0; j<r; j++){
			string s;
			cin>>s;
			mp[i][j] = s;

		}
	}
	return 1;
}

inline bool check(int &x,int &y,int &z){
	if(x < 0 || x >= r)return 0;
	if(y < 0 || y >= c)return 0;
	if(z < 0 || z >= l)return 0;
	if(mp[z][x][y] == '#')return 0;
	if(vis[x][y][z])return 0;
	return 1;
}

inline void solve(){
	queue<pair<node,int> > que;
	int nt[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
	for (int i=0; i<l; i++){
		for (int j=0; j<r; j++){
			for(int k=0;k<c;k++){
				// cout<<"mp[i][j][k] = "<<mp[i][j][k]<<endl;
				if(mp[i][j][k] == 'S'){
					que.push(make_pair(node(j,k,i),0));
					vis[i][j][k] = 1;
				}
				if(mp[i][j][k] == 'E'){
					ez = i;
					ex = j;
					ey = k;
				}
			}
		}
	}

	// cout<<"que.size() = "<<que.size()<<endl;
	while(!que.empty()){
		node &t = que.front().first;
		int &d = que.front().second;
		int nx,ny,nz;
		// cout<<"d = "<<d<<endl;

		if(t.x == ex && t.y == ey && t.z == ez){
			if(ans == -1)ans = d;
		}

		for (int i=0; i<6; i++){
			nx = t.x+nt[i][0];
			ny = t.y+nt[i][1];
			nz = t.z+nt[i][2];
			if(check(nx,ny,nz) == false)continue;
			que.push(make_pair(node(nx,ny,nz),d+1));
			vis[nx][ny][nz] = 1;
		}
		// cout<<"que.size() = "<<que.size()<<endl;
		que.pop();
	}
}

inline void ouput(){
	if(ans == -1)cout<<"Trapped!"<<endl;
	else cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(input()){
		init();
		solve();
		ouput();
	}
	return 0;
}
