#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int x[212345];
int y[212345];
bool dis[412345];

void solve(){
	int n,m;
	memset(dis,0,sizeof(dis));
	cin>>n>>m;
	for (int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			if(dis[abs(x[i]-x[j])+abs(y[i]-y[j])]==1){
				cout<<"YES"<<endl;
				return ;
			}
			else{
				dis[abs(x[i]-x[j])+abs(y[i]-y[j])]=1;
			}
		}
	}
	cout<<"NO"<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
