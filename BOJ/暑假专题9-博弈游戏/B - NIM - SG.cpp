#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// int f[1000000];

// int printsg(int t){
// 	int num = 0;
// 	for (int i=(t+1)/2; i<t; i++){
// 		if(num == f[i]){
// 			num ++ ;
// 			i = (t+1)/2 - 1;
// 		}
// 	}
// 	f[t] = num;
// 	return num;
// }

int sg(int t){
	if(t % 2 == 1){
		return sg(t/2);
	}
	else{
		return t/2;
	}
}

bool solve(){
	int n;
	cin>>n;
	if(n == 0)return false;

	int num = 0;
	// for (int i=(n+1)/2; i<n; i++){
	// 	num^=sg(i);
	// }
	if(sg(n))cout<<"Alice"<<endl;
	else cout<<"Bob"<<endl;


	return true;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// f[1]=0;
	// for (int i=1; i<=30; i++){
	//     cout<<"printsg(i) = "<<printsg(i)<<endl;
	// 	// cout<<"sg(i) = "<<sg(i)<<endl;
	// }
	// int t;cin>>t;
	while(solve());
	return 0;
}
