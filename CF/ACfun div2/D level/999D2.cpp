#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


queue<pair<ll,ll> > fre,lis[212345];
ll n , m;
ll a[212345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll ans = 0;

	ll t;
	for(long long i=0;i<n;i++){
		cin>>t;
		lis[t%m].push(make_pair(t,i));
	}

	for(long long i=0;i<n;i++){
		while(lis[i].size() > n/m){
			fre.push(lis[i].front());
			lis[i].pop();
		}

		while(!fre.empty() && lis[i].size() < n/m){
			lis[i].push(make_pair(fre.front().first+(i-(fre.front().first%m)+m)%m,fre.front().second));
			ans += (i - (fre.front().first%m) + m)%m;
			fre.pop();
		}
	}

	for(long long i=0;i<n;i++){
		while(lis[i].size() > n/m){
			fre.push(lis[i].front());
			lis[i].pop();
		}
		while(!fre.empty() && lis[i].size() < n/m){
			lis[i].push(make_pair(fre.front().first+(i-(fre.front().first%m)+m)%m,fre.front().second));
			ans += (i - (fre.front().first%m) + m)%m;
			fre.pop();
		}
	}


	for(long long i=0;i<m;i++){
		for(long long j=0;j<n/m;j++){
			a[lis[i].front().second] = lis[i].front().first;
			lis[i].pop();
		}
	}

	cout<<ans<<endl;
	for(long long i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
