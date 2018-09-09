#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<int,pair<int,int>> mp;
bool vis[555*555];
vector<vector<int> > tree(555);
typedef pair<int,pair<int,int> > piii;

piii make(int i,int j,int k){
	return make_pair(i,make_pair(j,k));
}

auto from = t.second.frist;
auto to = t.second.second;
auto len = t.first;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
	    for (int j=1; j<=m; j++){
			char ch;
			int cl,cr;
			cin>>ch>>cl>>ch>>cr;
			mp[i+(j-1)*m - 1] = make_pair(cl,cr);
	    }
	}

	priority_queue<piii,vector<piii>,greater<piii> > que;

	vis[1] = 1;
	que.push();

	while(!que.empty()){
		auto t = que.top();
		que.pop();
		if(t.second / m < (n-1)){
			que.push(make_pair())
		}
	}

	int q;
	cin>>q;
	for (int i=1; i<=q; i++){
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;

	}


	return 0;
}
