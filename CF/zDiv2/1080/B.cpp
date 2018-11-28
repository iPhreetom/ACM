// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	cin>>q;
	for (int i=1; i<=q; i++){
		int l,r;
		cin>>l>>r;

		int add = 0;
		bool nl = 0;
		if((r-l+1) % 2 == 1){
			nl = 1;
		}

		if(nl){// jishuge
			int ans = 0;
			add = (r-l+1)/2;

			if(l%2 == 0){
				add = -add;
			}

			if(r % 2 == 1){
				ans = -r + add;
			}
			else{
				ans = r + add;
			}


			cout<<ans<<endl;
		}
		else{
			int ans = 0;
			add = (r-l+1)/2;
			if(l%2 == 0){
				add = -add;
			}
			cout<<add<<endl;
		}
	}
	return 0;
}
