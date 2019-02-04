// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int i = 2;
	int cnt = 0;
	while(i < 1e9) {
		i *= 2;
		i -= 1;
		cnt++;
		cout<<"i = "<<i<<endl;
	}
	cout<<"cnt = "<<cnt<<endl;
	return 0;
}
