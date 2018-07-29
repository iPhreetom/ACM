#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll> > que;
vector<pair<pair<ll,ll>,ll> > vec;
ll n,m;
ll ans[212345];
ll sum;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m;

	ll t;
	for(int i=0;i<n;i++){
		cin>>t;
		vec.push_back(make_pair(make_pair(t,1),i));
	}

	for(int i=0;i<n;i++){
		cin>>vec[i].first.second;
		ans[i] = vec[i].first.second;
	}

	sort(vec.begin(),vec.end());

	if(m != 0)
	for(int i=0;i<n;i++){
		if(i<m){
			ans[vec[i].second] += sum;

			que.push(vec[i].first.second);
			sum += vec[i].first.second;
		}
		else{
			ans[vec[i].second] += sum;

			//update sum
			if(vec[i].first.second > que.top()){
				sum -= que.top();
				que.pop();
				que.push(vec[i].first.second);
				sum += vec[i].first.second;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
