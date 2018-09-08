	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	using namespace std;


	vector<int> arr;
	bool v[12345];

	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

		int len,m;
		cin>>len>>m;

		int l,r;
		for(int i=0;i<m;i++){
			cin>>l>>r;
			for(int i=l;i<=r;i++)v[i]=1;
		}

		int ans =0 ;
		for(int i=0;i<=len;i++){
			if(v[i] == 0)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
