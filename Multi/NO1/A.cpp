#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;



int n;
int t;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>t;
	while(t--){
		cin>>n;
		if(n % 3 == 0){
			cout<<(n/3)*(n/3)*(n/3)<<endl;
		}else if(n % 4 == 0){
			cout<<(n/2)*(n/4)*(n/4)<<endl;
		}else {
			cout<<-1<<endl;
		}
	}
	return 0;
}
