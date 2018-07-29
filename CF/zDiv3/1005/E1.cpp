#include<bits/stdc++.h>
#define int long long
using namespace std;


int n,m,ans;
map<int,int> mp;
bool mid = 0;
int sum;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;

	mp[0]=1;

	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t > m){
			sum++;
		}
		if(t < m){
			sum--;
		}

		if(t == m){
			mid = 1;
		}

		if(mid){
			ans += mp[sum];
		}
		else{
			mp[sum]++;
		}
	}

	cout<<ans<<endl;



	return 0;
}
