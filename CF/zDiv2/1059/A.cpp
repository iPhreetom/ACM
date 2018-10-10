// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,l,a;
	cin>>n>>l>>a;
	// if(n == 0){
	// 	cout<<l/a<<endl;
	// }
	// else{
		int ls = 0;
		int sum = 0;
		for (int i=0; i<n; i++){
			int ti,li;
			cin>>ti>>li;
			sum += (ti-ls)/a;
			ls = ti+li;
		}
		sum += (l-ls)/a;
		cout<<sum<<endl;
	// }
	return 0;
}
