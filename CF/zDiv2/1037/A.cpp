// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> a;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int ans = 0;
	int num = 1;
	while(1){
		n -= num;
		num *= 2;
		ans++;
		if(n <= 0)break;
	}
	cout<<ans<<endl;
	return 0;
}
