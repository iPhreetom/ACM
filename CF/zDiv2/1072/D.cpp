// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string mp[2123];
int cnt[2123][2123];
bool ok[2123][2123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n,k;
	cin>>n>>k;
	for (int i=0; i<n; i++){
		cin>>mp[i];
	}


	// get who is ok
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if(i == 0){
				// first
				if(j == 0){
					if(mp[i][j] == 'a'){
						cnt[i][j] = 0;
					}
					else{
						cnt[i][j] = 1;
					}
				}

				else{// one line
					if(mp[i][j] != 'a'){
						cnt[i][j] = cnt[i][j-1]+1;
					}
					else{
						cnt[i][j] = cnt[i][j-1];
					}
				}
			}
			else{
				if(j == 0){
					if(mp[i][j] != 'a'){
						cnt[i][j] = cnt[i-1][j]+1;
					}
					else{
						cnt[i][j] = cnt[i-1][j];
					}
				}
				else{
					if(mp[i][j] != 'a'){
						cnt[i][j] = min(cnt[i-1][j],cnt[i][j-1])+1;
					}
					else{
						cnt[i][j] = min(cnt[i-1][j],cnt[i][j-1]);
					}
				}
			}
		}
	}

	// bfs()
	typedef pair<char,pair<int,int>> qi;
	priority_queue< qi, vector<qi> ,greater<qi> > que1;
	priority_queue< qi, vector<qi> ,greater<qi> > que2;

	int mx = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			int dis = i+j;
			if(dis >= mx && cnt[i][j] <= k){
				mx = dis;
			}
		}
	}

	if(mx == n*2-1){
		for (int i=0; i<n; i++){
			cout<<'a';
			cout<<endl;
		}
	}
	else{
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				int dis = i+j;
				if(dis == mx && cnt[i][j] <= k){
					que1.push(make_pair(mp[i][j],make_pair(i,j)));
				}
			}
		}

		// get que1

		string ans;
		for (int i=0; i<mx+1; i++)ans.push_back('a');
		bool odd = 1;

		if(que1.empty()){
			ans.pop_back();
			que1.push(make_pair(mp[0][0],make_pair(0,0)));
			ans.push_back(mp[0][0]);
		}
		while(!que1.empty() || !que2.empty()){
			if(odd){
				odd = !odd;
				char mn = que1.top().first;
				int x,y;
				x = que1.top().second.first;
				y = que1.top().second.second;
				ans.push_back(mp[x][y]);

				while(!que1.empty()){
					int x,y;
					char ch = que1.top().first;
					x = que1.top().second.first;
					y = que1.top().second.second;

					que1.pop();
					if(ch != mn){
						continue;
					}


					int nx = x+1;
					int ny = y;
					if(nx < n && ny < n){
						que2.push(make_pair(mp[nx][ny],make_pair(nx,ny)));
					}
					nx = x;
					ny = y+1;
					if(nx < n && ny < n){
						que2.push(make_pair(mp[nx][ny],make_pair(nx,ny)));
					}
				}
			}
			else{
				odd = !odd;

				char mn = que2.top().first;
				int x,y;
				x = que2.top().second.first;
				y = que2.top().second.second;
				ans.push_back(mp[x][y]);

				while(!que2.empty()){
					int x,y;
					char ch = que2.top().first;
					x = que2.top().second.first;
					y = que2.top().second.second;

					que2.pop();
					if(ch != mn){
						continue;
					}


					int nx = x+1;
					int ny = y;
					if(nx < n && ny < n){
						que1.push(make_pair(mp[nx][ny],make_pair(nx,ny)));
					}
					nx = x;
					ny = y+1;
					if(nx < n && ny < n){
						que1.push(make_pair(mp[nx][ny],make_pair(nx,ny)));
					}
				}
			}
		}

		for (int i=0; i<ans.size(); i++){
			if(i < mx+1){
				cout<<ans[i];
			}
			else if(i == mx+1){
				continue;
			}
			else{
				cout<<ans[i];
			}
		}
		cout<<endl;
	}
	return 0;
}
