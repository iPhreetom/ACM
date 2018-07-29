#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<ll> a;
vector<ll> ans;
ll sum = 0;
vector<ll> em;
vector<ll> en;
vector<ll> od;
ll sufa[212345],sufb[212345];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// cout<<"??"<<endl;
	cin>>n>>m;

	em.push_back(0);

	for(int i=0;i<n;i++){
		ll t;
		cin>>t;
		em.push_back(t);
	}

	// sort(ans.rbegin(),ans.rend());
	// sum += ans[0]-1;
	// cout<<sum<<endl;


	em.push_back(m);
	for(int i=1;i<em.size();i++){
		if(i%2 == 1){
			od.push_back(em[i]-em[i-1]);
			en.push_back(0);
		}
		else{
			en.push_back(em[i]-em[i-1]);
			od.push_back(0);
		}
	}


	for(int i=en.size()-1;i>=0;i--){
		sufa[i]+=od[i];
		sufa[i]+=sufa[i+1];
		sufb[i]+=en[i];
		sufb[i]+=sufb[i+1];
	}

	// ll num = 0;
	sum = 0;

	// for(auto I:em)cout<<I<<" ";
	// cout<<endl;
	// for(auto I:od)cout<<I<<" ";cout<<endl;
	bool change = 0;
	for(int i=0;i<en.size();i++){
		// cout<<sufa[i]<<"   "<<sufb[i]<<endl;

		if(sufa[i] < sufb[i]){
			sum += od[i];
			sum += sufb[i];
			change = 1;
			break;
		}
		else{
			sum += od[i];
		}
	}
	if(change)sum--;
	cout<<sum<<endl;

	return 0;
}
