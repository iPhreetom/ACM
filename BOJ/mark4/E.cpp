
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > a(312345);
int p[321345];
int n,k,d;
int ans = 0;
int book[312345];

void dfs(int n){
	book[n] = 1;
	// cout<<n<<endl;
	for(int i=0;i<a[n].size();i++){
		if(book[a[n][i]] == 1)ans++;
		else dfs(a[n][i]);
	}
}
set<pair<int,int>> lis;
queue<int> que1,que2;
void bfs(int n){
	int count = 0;
	bool first = 1;
	while(!que1.empty())que1.pop();
	while(!que2.empty())que2.pop();
	que1.push(n);
	while(count<d && (!que1.empty() || !que2.empty())){
		count++;
		if(first){
			while(!que1.empty()){
				int tp = que1.front();
				que1.pop();
				for(int i=0;i<a[tp].size();i++){
					if(book[a[tp][i]]==1){
						ans++;
					}
					else{
						book[a[tp][i]]=1;
						que2.push(a[tp][i]);
					}
				}
			}
		}
		else{
			while(!que2.empty()){
				int tp = que2.front();
				que2.pop();
				for(int i=0;i<a[tp].size();i++){
					if(book[a[tp][i]]==1){
						ans++;
					}
					else{
						book[a[tp][i]]=1;
						que1.push(a[tp][i]);
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>d;
	int v,u;
	for(int i=0;i<k;i++){
		cin>>p[i];
		book[p[i]]=1;
	}
	for(int i=0;i<n-1;i++){
		cin>>v>>u;
		a[v].push_back(u);
		a[u].push_back(v);
	}


	// for(int i=0;i<10;i++){
	// 	cout<<book[i]<<' ';
	// }cout<<endl;
	for(int i=0;i<k;i++){
		bfs(p[i]);
	}
	cout<<ans/2<<endl;
	return 0;
}
