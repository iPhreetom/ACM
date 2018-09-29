// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int b[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		memset(b,0,sizeof(b));
		map<int,int> a;
		int n,m;
		int num = 0;


		cin>>n>>m;

		for (int i=1; i<=n; i++){
			cin>>b[i];
			if(b[i] != 0){
				a[b[i]]++;
				if(a[b[i]] == 1)num++;
			}
		}

		while(m--){
			int tp;
			cin>>tp;
			if(tp == 2){
				cout<<num<<endl;
			}
			else{
				int p,v;
				cin>>p>>v;
				if(b[p] == 0)
			}
		}
	}
	return 0;
}
