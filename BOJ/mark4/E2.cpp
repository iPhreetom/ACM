
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>> > a(312345);
int p[321345];
int n,k,d;
int ans = 0;
int book[312345];

set<int> lis;
set<int> last;
queue<int> que1,que2;
void bfs(int n){
	int count = 0;
	bool first = 1;
	while(!que1.empty())que1.pop();
	while(!que2.empty())que2.pop();
	que1.push(n);
	last.clear();
	while(count<=d && (!que1.empty() || !que2.empty())){
		if(count == d){
			// cout<<"!!!"<<endl;
			if(first){
				while(!que1.empty()){

					int tp = que1.front();
					last.insert(tp);

					que1.pop();
					for(int i=0;i<a[tp].size();i++){
						if(book[a[tp][i].first]==1 && last.count(a[tp][i].first)==0){
							ans++;
							lis.insert(a[tp][i].second);
							// cout<<ans<<endl;
						}
					}
				}
				first = !first;
			}
			else{
				while(!que2.empty()){
					int tp = que2.front();
					last.insert(tp);
					que2.pop();
					for(int i=0;i<a[tp].size();i++){
						if(book[a[tp][i].first]==1 && last.count(a[tp][i].first)==0){
							ans++;
							lis.insert(a[tp][i].second);
						}
					}
				}
				first = !first;
			}
		}
		else{
			// cout<<"---"<<endl;
			if(first){
				while(!que1.empty()){

					int tp = que1.front();
					last.insert(tp);

					que1.pop();
					for(int i=0;i<a[tp].size();i++){
						if(book[a[tp][i].first]==1 && last.count(a[tp][i].first)==0){
							ans++;
							lis.insert(a[tp][i].second);
							// cout<<ans<<endl;
						}
						else{
							book[a[tp][i].first]=1;
							que2.push(a[tp][i].first);
							// cout<<"tp"<<a[tp][i].first<<endl;
						}
					}
				}
				first = !first;
			}
			else{
				while(!que2.empty()){
					int tp = que2.front();
					last.insert(tp);
					que2.pop();
					for(int i=0;i<a[tp].size();i++){
						if(book[a[tp][i].first]==1 && last.count(a[tp][i].first)==0){
							ans++;
							lis.insert(a[tp][i].second);
						}
						else{
							book[a[tp][i].first]=1;
							que1.push(a[tp][i].first);
						}
					}
				}
				first = !first;
			}
		}
		count++;
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
	for(int i=1;i<=n-1;i++){
		cin>>v>>u;
		a[v].push_back(make_pair(u,i));
		a[u].push_back(make_pair(v,i));
	}



	for(int i=0;i<k;i++){
		bfs(p[i]);
		// cout<<ans<<endl;
	}

	// for(int i=0;i<10;i++){
	// 	cout<<book[i]<<' ';
	// }cout<<endl;

	cout<<lis.size()<<endl;
	for(auto i:lis)cout<<i<<' ';
	return 0;
}
