// fyt
#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int mp[9001][9001];
inline int solve4(int x,int y,int k){
	int ans = 0;
	int sq = sqrt(k);
	for(int mx = 0; mx <= sq; mx++){
		int my = sqrt(k-mx*mx);
		if((my * my) == (k-mx*mx)){// 合法
			int nx,ny;
			// 四个点

			if(mx == 0){
				if(my == 0){
					// r-t
					nx = mx + x;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						ans += mp[nx][ny];
					}
				}
				else{
					// r-t
					nx = mx + x;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						ans += mp[nx][ny];
					}

					// l-b
					nx = x - mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						ans += mp[nx][ny];
					}
				}
			}
			else{
				// mx != 0
				if(my == 0){
					// r-t
					nx = mx + x;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						ans += mp[nx][ny];
					}

					// l-b
					nx = x - mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						ans += mp[nx][ny];
					}
				}
				else{
					// r-t
					nx = mx + x;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						ans += mp[nx][ny];
					}

					// l-b
					nx = x - mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						ans += mp[nx][ny];
					}
					// r-b
					nx = x + mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						ans += mp[nx][ny];
					}

					// l-t
					nx = x - mx;
					ny = y + my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						ans += mp[nx][ny];
					}
				}
			}
		}
	}
	return ans;
}
inline void solve3(int x,int y,int k,int w){
	int ans = 0;
	int sq = sqrt(k);
	for(int mx = 0; mx <= sq; mx++){
		int my = sqrt(k-mx*mx);
		if((my * my) == (k-mx*mx)){// 合法
			int nx,ny;
			// 四个点

			if(mx == 0){
				if(my == 0){
					// r-t
					nx = mx;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}
				}
				else{
					// r-t
					nx = mx;
					ny = my + y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}

					// l-b
					nx = x;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}
				}

			}
			else{
				// mx != 0
				if(my == 0){
					// r-t
					nx = mx + x;
					ny = y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}

					// l-b
					nx = x - mx;
					ny = y;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}
				}
				else{// mx my != 0
					// r-t
					nx = x + mx;
					ny = y + my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}

					// l-b
					nx = x - mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}

					// r-b
					nx = x + mx;
					ny = y - my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}

					// l-t
					nx = x - mx;
					ny = y + my;
					if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
						// cout<<"nx = "<<nx<<' ';
						// cout<<"ny = "<<ny<<endl;
						if(mp[nx][ny] != 0){
							mp[nx][ny] += w;
						}
					}
				}
			}
		}
	}
}
//   2 2 0 0 0
// 2   2 0 0
//   1     0 0
// 2   2 0 0
// 0 2 2 0 0 0

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	int cnt = 0;

	while(t--){
		cnt++;

		cout<<"Case #"<<cnt<<':'<<endl;
		int lans = 0;
		int n,m;
		// memset(mp,0,sizeof(mp));
		vector<pair<int,int>> v;
		cin>>n>>m;
		for (int i=1; i<=n; i++){
			int x,y,w;
			cin>>x>>y>>w;
			v.push_back(make_pair(x,y));
			mp[x][y] = w;
		}
		for (int i=1; i<=m; i++){
			int tp;
			cin>>tp;
			if(tp == 1){
				int x,y,w;
				cin>>x>>y>>w;
				x = (x+lans)%6000 + 1;
				y = (y+lans)%6000 + 1;
				v.push_back(make_pair(x,y));
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				mp[x][y] = w;
			}
			if(tp == 2){
				int x,y;
				cin>>x>>y;
				x = (x+lans)%6000 + 1;
				y = (y+lans)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				mp[x][y] = 0;
			}
			if(tp == 3){
				int x,y,k,w;
				cin>>x>>y>>k>>w;
				x = (x+lans)%6000 + 1;
				y = (y+lans)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				solve3(x,y,k,w);
			}
			if(tp == 4){
				int x,y,k;
				cin>>x>>y>>k;
				x = (x+lans)%6000 + 1;
				y = (y+lans)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				lans = solve4(x, y, k);
				cout<<lans<<endl;
			}
		}
		for (int i=0; i<v.size(); i++){
			mp[v[i].first][v[i].second] = 0;
		}
		// for (int i=0; i<6000; i++){
		//     for (int j=0; j<6000; j++){
		//         if(mp[i][j] == 1){
		// 			cout<<"!"<<endl;
		// 		}
		//     }
		// }
	}
	return 0;
}
