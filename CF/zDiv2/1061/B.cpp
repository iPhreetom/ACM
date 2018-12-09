// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	priority_queue<int> que;
	for (int i=1; i<=n; i++){
		int x;cin>>x;
		que.push(x);
	}

	int cnt = 0;
	int ans = 0;
	int ls = que.top();
	que.pop();

	while(!que.empty()){
		if(que.top() == ls && ls != 1){
			cnt++;
			ans += max(ls-1 , 1LL);
		}
		else{
			int dif = ls-que.top()-1;
			if(ls > 1){
				if(cnt >= dif){
					cnt -= dif;
					ans += ls-1;
				}
				else{
					ans += que.top()+cnt;
					cnt = 0;
				}
			}
		}
		ls = que.top();
		que.pop();
	}
	if(ls != 1) {
		if(cnt >= ls - 1){
			ans += ls - 1;
		}
		else {
			ans += cnt;
		}
	}
	cout<<ans<<endl;

	return 0;
}
