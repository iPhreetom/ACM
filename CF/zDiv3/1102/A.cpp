#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;


	if(((n+1)/2)%2 == 0){
		cout << 0 << endl;
	}
	else {
		cout << 1 << endl;;
	}
	return 0;
}
