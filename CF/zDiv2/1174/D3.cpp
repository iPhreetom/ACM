// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x;
	cin >> n >> x;
	if (n == 1 && x == 1) {
		cout << 0 << endl;
		return 0;
	}

	set<int> s;
	int mx = pow(2,n);
	for (int i=1; i<mx; i++){
		if (i != x) {
			s.insert(i);
		}
	}

	vector<int> ans;
	while (!s.empty()) {
		int now = *s.begin();
		ans.push_back(now);
		s.erase(now);
		if (s.count(now^x) != 0) s.erase(now^x);
	}
	vector<int> lis;
	lis.push_back(ans[0]);
	for (int i=1; i<ans.size(); i++){
		lis.push_back(ans[i]^ans[i-1]);
	}
	cout << lis.size() << endl;
	for (int i=0; i<lis.size(); i++){
	    cout<<lis[i]<<' ';
	}cout<<endl;
	return 0;
}
