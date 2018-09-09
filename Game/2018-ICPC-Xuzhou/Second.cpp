#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

set<int> xs;
set<int> ys;
vector<int> xv(51234);
vector<int> yv(51234);

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);



	int n;
	cin>>n;

	int ans=0;
	xs.insert(0);
	ys.insert(0);

	for (int i=1; i<=n; i++){
		int x,y;
		cin>>xv[i];
		cin>>yv[i];
	}
	for(int i=n;i>0;i--){
		xs.insert(xv[i]);
		ys.insert(yv[i]);
		auto lx = xs.lower_bound(xv[i]);
		auto ly = ys.lower_bound(yv[i]);
		lx--;
		ly--;
		ans += (xv[i] - *lx);
		ans += (yv[i] - *ly);
	}
	cout<<ans<<endl;
	return 0;
}
