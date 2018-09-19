// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int dif = 0;
	priority_queue<pair<int,int> > que;
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		dif += t;
		que.push(make_pair(t,1));
	}
	for (int i=0; i<n; i++){
	    int t;
		cin>>t;
		dif -= t;
		que.push(make_pair(t,2));
	}
	int now = 1;
	while(!que.empty()){
		if(now == 1){
			if(que.top().second != now){
				dif += que.top().first;
			}
			now = 2;
		}
		else{
			if(que.top().second != now){
				dif -= que.top().first;
			}
			now = 1;
		}
		que.pop();
	}
	cout<<dif<<endl;
	return 0;
}
