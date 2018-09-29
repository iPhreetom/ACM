// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


set<pair<int,int>> s;
int n,d,m;

void build(){
	queue<pair<int,int>> que;
	for (int i=0; i<=d; i++){
		que.push(make_pair(i,d-i));
	}
	for (int i=1; i<=d; i++){
		que.push(make_pair(i,d-i+1));
	}
	while(!que.empty()){
		s.insert(que.front());
		if(que.front().first + que.front().second + 2<= n + n - d){
			que.push(make_pair(que.front().first+1,que.front().second+1));
		}
		que.pop();
	}
	// cout<<"----"<<endl;
	// for(auto i:s){
	// 	cout<<i.first<<' '<<i.second<<endl;
	// }
	// cout<<"----"<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>d;
	build();
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		if(s.count(make_pair(x,y)) == 0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
