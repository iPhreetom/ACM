#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	int ans = 0 ;
	for(int i=1;i<=n;i++){
		int num = 0;
		for(int j=1;j<=sqrt(i);j++){
			if(i % j == 0){
				if(i/j == j)num++;
				else num+=2;
			}
		}
		if(num%2 == 1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
