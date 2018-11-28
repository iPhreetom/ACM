// fyt
#include<bits/stdc++.h>
#define endl '\n'
// #define int long long
using namespace std;

long long mp[7001][7001];
inline long long solve4(int x,int y,int k){
	vector<pair<int,pair<int,long long> > >  v;
	long long ans = 0;
	int sq = sqrt(k);
	for(int mx = 0; mx <= sq; mx++){
		int my = sqrt(k-mx*mx);
		if(my * my == k-mx*mx){// 合法
			int nx,ny;
			// 四个点

			// if(mx == 0){
			// 	if(my == 0){
			// 		// r-t
			// 		nx = mx + x;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			// 	}
			// 	else{
			// 		// r-t
			// 		nx = mx + x;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			//
			// 		// l-b
			// 		nx = x - mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			// 	}
			// }
			// else{
			// 	// mx != 0
			// 	if(my == 0){
			// 		// r-t
			// 		nx = mx + x;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			//
			// 		// l-b
			// 		nx = x - mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			// 	}
			// 	else{
			// 		// r-t
			// 		nx = mx + x;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			//
			// 		// l-b
			// 		nx = x - mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			// 		// r-b
			// 		nx = x + mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			//
			// 		// l-t
			// 		nx = x - mx;
			// 		ny = y + my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			ans += mp[nx][ny];
			// 			v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 			mp[nx][ny] = 0;
			// 		}
			// 	}
			// }
			// r-t
			nx = mx + x;
			ny = my + y;
			if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000 && mp[nx][ny] != 0){
				ans += mp[nx][ny];
				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
				mp[nx][ny] = 0;
			}

			// l-b
			nx = x - mx;
			ny = y - my;
			if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000 && mp[nx][ny] != 0){
				// cout<<"nx = "<<nx<<' ';
				// cout<<"ny = "<<ny<<endl;
				ans += mp[nx][ny];
				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
				mp[nx][ny] = 0;
			}
			// r-b
			nx = x + mx;
			ny = y - my;
			if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000 && mp[nx][ny] != 0){
				// cout<<"nx = "<<nx<<' ';
				// cout<<"ny = "<<ny<<endl;
				ans += mp[nx][ny];
				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
				mp[nx][ny] = 0;
			}

			// l-t
			nx = x - mx;
			ny = y + my;
			if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000 && mp[nx][ny] != 0){
				// cout<<"nx = "<<nx<<' ';
				// cout<<"ny = "<<ny<<endl;
				ans += mp[nx][ny];
				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
				mp[nx][ny] = 0;
			}
		}
	}
	for (int i=0; i<v.size(); i++){
		mp[v[i].first][v[i].second.first] = v[i].second.second;
	}
	return ans;
}

inline void solve3(int x,int y,int k,int w){
	int sq = sqrt(k);
	vector<pair<int,pair<int,long long> > >  v;
	for(int mx = 0; mx <= sq; mx++){
		int my = sqrt(k-mx*mx);
		if(my * my == k-mx*mx){// 合法
			int nx,ny;
			// 四个点

			// if(mx == 0){
			// 	if(my == 0){
			// 		// r-t
			// 		nx = mx;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			// 	}
			// 	else{
			// 		// r-t
			// 		nx = mx;
			// 		ny = my + y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			//
			// 		// l-b
			// 		nx = x;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			// 	}
			//
			// }
			// else{
			// 	// mx != 0
			// 	if(my == 0){
			// 		// r-t
			// 		nx = mx + x;
			// 		ny = y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			//
			// 		// l-b
			// 		nx = x - mx;
			// 		ny = y;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			// 	}
			// 	else{// mx my != 0
			// 		// r-t
			// 		nx = x + mx;
			// 		ny = y + my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			//
			// 		// l-b
			// 		nx = x - mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			//
			// 		// r-b
			// 		nx = x + mx;
			// 		ny = y - my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			//
			// 		// l-t
			// 		nx = x - mx;
			// 		ny = y + my;
			// 		if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
			// 			// cout<<"nx = "<<nx<<' ';
			// 			// cout<<"ny = "<<ny<<endl;
			// 			if(mp[nx][ny] != 0){
			// 				mp[nx][ny] += w;
			// 				v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
			// 				mp[nx][ny] = 0;
			// 			}
			// 		}
			// 	}
			// }
			// r-t
			nx = x + mx;
			ny = y + my;
			if(nx > 0 && nx <= 6000 && ny > 0 && ny <= 6000){
				if(mp[nx][ny] != 0){
					mp[nx][ny] += w;
					v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
					mp[nx][ny] = 0;
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
					v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
					mp[nx][ny] = 0;
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
					v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
					mp[nx][ny] = 0;
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
					v.push_back(make_pair(nx,make_pair(ny,mp[nx][ny])));
					mp[nx][ny] = 0;
				}
			}
		}
	}
	for (int i=0; i<v.size(); i++){
		mp[v[i].first][v[i].second.first] = v[i].second.second;
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
		long long lans = 0;
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
				x = (lans+x)%6000 + 1;
				y = (lans+y)%6000 + 1;
				v.push_back(make_pair(x,y));
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				mp[x][y] = w;
			}
			if(tp == 2){
				int x,y;
				cin>>x>>y;
				x = (lans+x)%6000 + 1;
				y = (lans+y)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				mp[x][y] = 0;
			}
			if(tp == 3){
				int x,y,k,w;
				cin>>x>>y>>k>>w;
				x = (lans+x)%6000 + 1;
				y = (lans+y)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				solve3(x,y,k,w);
			}
			if(tp == 4){
				int x,y,k;
				cin>>x>>y>>k;
				x = (lans+x)%6000 + 1;
				y = (lans+y)%6000 + 1;
				// cout<<"x = "<<x<<' ';
				// cout<<"y = "<<y<<endl;
				lans = solve4(x, y, k);
				cout<<lans<<endl;
			}
		}
		for (int i=0; i<v.size(); i++){
			mp[v[i].first][v[i].second] = 0;
		}
	}
	return 0;
}
