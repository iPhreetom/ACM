#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<string,int> dui;
vector<pair<int,int> > mp[11234];
bool vis[11234][2];

void bfs(string &a,string &b,string &c){
	queue<pair<int,int> > que;
	que.push(make_pair(dui[a],0));

	while(!que.empty()){
		int f = que.front().first;
		int t = que.front().second;
		cout<<"f = "<<f<<endl;
		vis[f][t] = 1;
		for (int i=0; i< mp[f].size(); i++){
			if(t == 1){
				if(vis[mp[f][i].first][1] != 1){
					que.push(make_pair(mp[f][i].first,1));
				}
			}
			else{
				if(vis[mp[f][i].first][t] != 1){
					que.push(make_pair(mp[f][i].first,t));
				}
			}
		}
		que.pop();
	}

	if(b == "is-a"){
		if(vis[dui[c]][0]){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
	}
	else{
		if(vis[dui[c]][1]){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
	}
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	int cnt = 0;
	cin>>n>>q;

	for (int i=0; i<n; i++){
		string a,b,c;
		cin>>a>>b>>c;
		if(dui.count(a) == 0){
			dui[a] = cnt++;
		}
		if(dui.count(c) == 0){
			dui[c] = cnt++;
		}
		if(b == "is-a"){// 1
			mp[dui[a]].push_back(make_pair(dui[c],0));
		}
		else{
			mp[dui[a]].push_back(make_pair(dui[c],1));
		}
	}

	while(q--){
		string a,b,c;
		memset(vis,0,sizeof(vis));
		bfs(a,b,c);
	}
	return 0;
}
