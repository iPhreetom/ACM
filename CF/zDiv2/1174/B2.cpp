// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	int all_even = 1;
	int all_odd = 1;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		ans.push_back(t);
		if (t % 2 == 1) all_even = 0;
		else all_odd = 0;
	}
	if (all_even || all_odd) {
		for (int i=0; i<ans.size(); i++){
		    cout<<ans[i]<<' ';
		}cout<<endl;
	}
	else {
		sort(ans.begin(),ans.end());
		for (int i=0; i<ans.size(); i++){
		    cout<<ans[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
