// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;

	priority_queue<int,vector<int>,greater<int> > que;
	for (int i=1; i<=n; i++){
		int x;
		cin>>x;
		que.push(x);
	}

	int sub = 0;
	for (int i=1; i<=k; i++){
		if(que.empty()){
			cout<<0<<endl;
			// cerr<<"??"<<endl;
		}
		else{
			while(!que.empty() && que.top() <= sub){
				que.pop();
			}
			if(que.empty()){
				cout<<0<<endl;
			}
			else{
				que.top();
				int ans = que.top()-sub;
				cout<<ans<<endl;
				sub += ans;
				que.pop();
			}
		}
	}

	return 0;
}
