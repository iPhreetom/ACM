#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<int> lis;
vector<int> difer;

void solve(){
	int ans = 0;
	// int n;cin>>n;
	for(int n= 1;n<=10000;n++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=i-1; j++){
				ans += (__gcd(i+j,i-j) == 1);
			}
		}
		cout<<ans<<endl;
		lis.push_back(ans);
		if(lis.size() != 1){
			cout<<"dif = "<<lis[(int)lis.size()-1]-lis[(int)lis.size()-2]<<endl;
			difer.push_back(lis[(int)lis.size()-1]-lis[(int)lis.size()-2]);
			if(difer.size() != 1){
				cout<<"differ = "<<difer[(int)difer.size()-1]-difer[(int)difer.size()-2]<<endl;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
