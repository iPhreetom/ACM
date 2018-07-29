
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
ll x,y,tx;
pair<ll,ll> my=make_pair(0,1),my2=make_pair(0,1);
ll n;
vector<pair<int,int>> a;
ll ax[312345],ay[312345];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;


	for(int i=1;i<=n;i++){
		cin>>x>>y;
		ax[i] = x;
		ay[i] = y;
		tx += x;
		if(y > my.first){
			// cout<<"i:"<<i<<endl;
			my2.second = my.second;
			my2.first = my.first;
			my.first = y;
			my.second = i;
		}else if(y > my2.first){
			my2.first = y;
			my2.second = i;
		}
	}
	// cout<<"kk"<<endl;
	// cout<<my.first<<my.second<<endl;
	for(int i=1;i<=n;i++){
		x = ax[i];
		y = ay[i];
		if(i == my.second){
			// cout<<tx-x<<"-----"<<my2.first<<endl;
			cout<<(tx-x) * my2.first<<' ';
		}
		else{
			cout<<(tx-x) * my.first <<' ';
			// cout<<tx-x<<"------"<<my.first<<endl;
		}
	}
	return 0;
}
