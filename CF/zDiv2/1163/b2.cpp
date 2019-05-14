// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	map<int,int> mp;
	map<int,int> rmq; // the number of val i in the prefix is rmp[i];
	int mx = 0;
	int mn = 1;

	int n;
	cin >> n;
	vector<int> v(n+1);
	int ans = 0;
	for (int i=1; i<=n; i++){
		cin >> v[i];
		if(mp.count(v[i]) == 0) {
			mp[v[i]] ++ ;
			mx = max(mx, mp[v[i]]);
			if (rmq.count(1) == 0) mn = 1;
			rmq[ mp[v[i]] ] ++;
		}
		else {
			rmq[ mp[v[i]]+1 ]++;
			if (rmq[ mp[v[i]] ] == 1) {
				rmq.erase(mp[v[i]]);
				mn = rmq.begin()->first;
			}
			else {
				rmq[ mp[v[i]] ] --;
			}
			mp[v[i]] ++ ; // v[i] number plus one
			mx = max(mx, mp[v[i]]);
		}

		if(rmq.size() == 2) {
			int num_mx = rmq[mx];
			int num_mn = rmq[mn];

			if ((mx - mn == 1 && num_mx == 1) || (mn == 1 && num_mn == 1)) {
				ans = i;
			}
		}
		else if(rmq.size() == 1){
			int num = rmq[mx];
			if ((mx == 1)) {
				ans = i;
			}
			else if(num == 1) {
				ans = i;
			}
		}
		// cout<<"mx = "<<mx<<endl;
		// cout<<"rmq[mx] = "<<rmq[mx]<<endl;
		// cout<<"mn = "<<mn<<endl;
		// cout<<"rmq[mn] = "<<rmq[mn]<<endl;
		// cout << endl;
	}
	cout << ans << endl;

	return 0;
}
