#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


// vector<int> arr;
vector<pair<int,int> > a;
int ans[212345];
priority_queue<int> que;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		que.push(t);
	}

	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		a.push_back(make_pair(t,i));
	}

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	while(!que.empty()){
		for(int i=0;i<m && !que.empty();i++){
			ans[a[i].second] += que.top();
			que.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}cout<<endl;

	return 0;
}
