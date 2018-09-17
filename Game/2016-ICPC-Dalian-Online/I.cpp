// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

set<int> mp[212345];
int d[212345];
queue<int> que;
queue<int> del;
set<int> lis;
int n,m;

void init(){
	// memset(vis,0,sizeof(vis));
	// memset(d,0,sizeof(d));
	for (int i=0; i<212345; i++){
	    mp[i].clear();
	}
	lis.clear();
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;cin>>tt;
	while(tt--){
		init();
		int s;

		cin>>n>>m;
		for (int i=0; i<m; i++){
			int u,v;
			cin>>u>>v;
			// mp.insert(make_pair(min(u,v),max(u,v)));
			mp[v].insert(u);
			mp[u].insert(v);
		}

		cin>>s;
		que.push(s);

		for (int i=1; i<=n; i++){
			lis.insert(i);
		}
		lis.erase(s);
		d[s] = 0;
		int index = 1;//deep
		while(!que.empty()){
			for(auto i:lis){
				if(mp[que.front()].count(i) == 0){
					d[i] = d[que.front()]+1;
					que.push(i);
					del.push(i);
				}
			}

			while(!del.empty()){
				lis.erase(del.front());
				del.pop();
			}
			que.pop();
			index++;
		}

		bool first = 1;
		for (int i=1; i<=n; i++){
			if(i == s)continue;
			if(first){
				if(lis.count(i) == 0){
					cout<<d[i];
				}
				else{
					cout<<-1;
				}
				first = 0;
			}
			else{
				if(lis.count(i) == 0){
					cout<<' '<<d[i];
				}
				else{
					cout<<' '<<-1;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
