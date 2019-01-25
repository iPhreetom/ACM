#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;

string mp[1005];
int ans[10];
int n,m,p;
string tp;
int speed[10];

queue< pair<int, pair<int,int> > > lis;
typedef pair<int, pair<int,int> > pii;

void bfs() {
	priority_queue< pii ,vector<pii> , greater<pii> > que;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if(mp[i][j] != '.' && mp[i][j] != '#') {
				que.push(make_pair(mp[i][j]-'0',make_pair(i,j)));
			}
		}
	}

	int nt[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

	bool first = 1;
	while(first || !lis.empty()){
		first = 0;

		while(!lis.empty()) {
			que.push(lis.front());
			lis.pop();
		}

		while(!que.empty()) {
			int tx = que.top().second.first;
			int ty = que.top().second.second;
			int v = que.top().first;
			que.pop();

			queue<pair<pair<int,int>,int> > minique;
			queue<pair<pair<int,int>,int> > minique2;
			minique.push(make_pair(make_pair(tx,ty),0));
			while(!que.empty() && que.top().first == v){
				tx = que.top().second.first;
				ty = que.top().second.second;
				minique.push(make_pair(make_pair(tx,ty),0));
				que.pop();
			}

			// queue<pair<int,int> > re;

			bool que2 = 0;
			while(!minique.empty() || !minique2.empty()) {
				if(que2) {
					while(!minique2.empty()){
						int x = minique2.front().first.first;
						int y = minique2.front().first.second;
						int dis = minique2.front().second;
						minique2.pop();

						for (int i=0; i<4; i++){
							int nx = x+nt[i][0];
							int ny = y+nt[i][1];
							if(mp[nx][ny] == '.') {
								if(dis + 1 < speed[v]){
									minique.push(make_pair(make_pair(nx,ny),dis+1));
								}
								lis.push(make_pair(v,make_pair(nx,ny)));
								mp[nx][ny] = v+'0';
							}
						}
					}
				}
				else{
					while(!minique.empty()) {
						int x = minique.front().first.first;
						int y = minique.front().first.second;
						int dis = minique.front().second;
						minique.pop();

						for (int i=0; i<4; i++){
							int nx = x+nt[i][0];
							int ny = y+nt[i][1];
							if(mp[nx][ny] == '.') {
								if(dis + 1 < speed[v]){
									minique2.push(make_pair(make_pair(nx,ny),dis+1));
								}
								lis.push(make_pair(v,make_pair(nx,ny)));
								mp[nx][ny] = v+'0';
							}
						}
					}

				}
				que2 = !que2;
			}
		}
	}
}

void check() {
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if(mp[i][j] != '.' && mp[i][j] != '#') {
				ans[mp[i][j]-'0']++;
			}
		}
	}
	for (int i=1; i<=p; i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>p;

	for (int i=1; i<=m; i++){
		tp.push_back('#');
	}
	mp[0] = tp;
	mp[n+1] = tp;

	for (int i=1; i<=p; i++){
		cin>>speed[i];
	}

	for (int i=1; i<=n;	i++){
		string s;
		cin>>s;
		mp[i].push_back('#');
		mp[i] += s + '#';
	}

	bfs();
	check();

	return 0;
}
