// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q;
	double k,p;
	cin>>k>>q;
	while(q--){
		cin>>p;
		double ans = 0;
		double mx = (p-(1e-7))/2000.0;
		int cnt = 1;
		while(1){
			ans += 1/k;
			if(cnt >= k && ans >= mx+1e-7){
				cout<<cnt<<endl;
				break;
			}
			cnt++;
		}
	}
	return 0;
}
