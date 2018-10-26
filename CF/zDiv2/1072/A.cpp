// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int chang,kuang,cnt;
	cin>>chang>>kuang>>cnt;
	int ans = 0;
	for (int i=1; i<=cnt; i++){
		ans += chang*2;
		ans += kuang*2;
		chang-=4;
		kuang-=4;
		ans -= 4;
	}
	cout<<ans<<endl;
	return 0;
}
