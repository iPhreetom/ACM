#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll> > que;
ll a[105];
ll even,odd;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n,b;
	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]%2==1)odd++;
		else even++;

		if(odd==even && i!=n-1){
			que.push(abs(a[i+1]-a[i]));
		}
	}

	ll ans = 0;
	while(!que.empty()){
		if(b >= que.top()){
			ans++;
			// cout<<que.top()<<endl;
			b-=que.top();
			que.pop();
		}
		else{
			// cout<<ans<<endl;
			// return 0;
			break;
		}
	}

	cout<<ans<<endl;
	return 0;
}
