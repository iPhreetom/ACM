#include<bits/stdc++.h>
// #define int long long
using namespace std;


int mod =  998244353;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	__int128 n=1;
	long long ab = pow(2,63);
	for(int i=0;i<2;i++){
		n *= __int128(ab);
	}

	string a;
	while(n){
		int q = n%10;
		a.push_back(q+'0');
		n /= 10;
	}
	reverse(a.begin(),a.end());
	cout<<a<<endl;
	cout<<a.size()<<endl;



	return 0;
}
