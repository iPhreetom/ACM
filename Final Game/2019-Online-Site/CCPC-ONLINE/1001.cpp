// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		unsigned int a,b;
		cin >> a >> b;
		unsigned c = (a&b);
		cout << max(1u,c) << endl;
	}
	return 0;
}
