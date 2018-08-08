// 天才罚时少女
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a[212345];
int w[212345];
bool vis[212345];
int q,p;
int n;



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int q = 0;
		cin>>w[0];
		q=w[0];
		for(int i=1;i<n;i++){
			cin>>w[i];
			q^=w[i];
		}

		for(int i=0;i<n-1;i++){
			int v,u;
			cin>>v>>u;
		}

		// cout<< (q^w[0]) <<endl;

		if((q^w[0])  == w[0]){
			cout<<"D"<<endl;
		}else{
			cout<<"Q"<<endl;
		}

	}
	return 0;
}
