// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


struct node{
	int x,y,nd,nu;
	node(){};
	node(int x,int y,int nd,int nu):x(x),y(y),nd(nd),nu(nu){};
};
deque<node> que;
string mp[2120];
bool vis[2123][2123];
int n,m;
int sx,sy;
int x,y;
int ans;

void bfs(){
	int nty[4] = {0,1,0,-1};
	int ntx[4] = {1,0,-1,0};
	// x move free
	// y move need
	// 0 right
	// 2 left
	// 1 up
	// 3 down

 	que.push_back(node(sx,sy,x,y));
	while(!que.empty()){
		node q = que.front();
		que.pop_front();
		for (int i=0; i<4; i++){
		    if(q.x + ntx[i] >= n || q.y + nty[i] >= m || q.x + ntx[i] < 0 || q.y + nty[i] < 0 || mp[q.x+ntx[i]][q.y+nty[i]] == '*' || vis[q.x+ntx[i]][q.y+nty[i]] == 1){
				continue;
			}
			else{
				if(i == 0){
					//
					ans++;
					vis[q.x+ntx[i]][q.y+nty[i]] = 1;
					que.push_front(node(q.x+ntx[i],q.y+nty[i],q.nd,q.nu));
				}
				if(i == 2){
					//
					ans++;
					vis[q.x+ntx[i]][q.y+nty[i]] = 1;
					que.push_front(node(q.x+ntx[i],q.y+nty[i],q.nd,q.nu));
				}
				if(i == 1){
					if(q.nu == 0)continue;
					ans++;
					vis[q.x+ntx[i]][q.y+nty[i]] = 1;
					que.push_back(node(q.x+ntx[i],q.y+nty[i],q.nd,q.nu-1));
				}
				if(i == 3){
					if(q.nd == 0)continue;
					ans++;
					vis[q.x+ntx[i]][q.y+nty[i]] = 1;
					que.push_back(node(q.x+ntx[i],q.y+nty[i],q.nd-1,q.nu));
				}
			}
		}
	}
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>sx>>sy;
	cin>>x>>y;

	sx--;
	sy--;
	vis[sx][sy] = 1;
	ans++;
	for (int i=0; i<n; i++){
		cin>>mp[i];
	}

	bfs();
	cout<<ans<<endl;
	return 0;
}
