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

	string a,b;
	cin >> a >> b;

	map<int,int> mp;
	map<int,int> ans;

	auto output = [&](){
		int cnt = 0;
		for (int i=0; i<n; i++){
		    if(a[i] == '1' && b[i] == '1' && ans[2] > 0) {
				ans[2] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '1' && b[i] == '0' && ans[1] > 0) {
				ans[1] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '0' && b[i] == '0' && ans[0] > 0) {
				ans[0] --;
				cout << i+1 << ' ';
			}
			else if(a[i] == '0' && b[i] == '1' && ans[-1] > 0) {
				ans[-1] --;
				cout << i+1 << ' ';
			}
		}
		cout << endl;
	};
	for (int i=0; i<n; i++){
	    if(a[i] == '1' && b[i] == '1') mp[2]++;
		else if(a[i] == '1' && b[i] == '0') mp[1]++;
		else if(a[i] == '0' && b[i] == '0') mp[0]++;
		else mp[-1]++;
	}

	for (int i=1; i<=n/2; i++){
		// check i;
		for (int j=0; j<=min(mp[1],n/2); j++){
			// j ge 1
			int one = j;
			int two = i-j;
			if(two > mp[2]) continue;

			int restwo = mp[2] - two;
			if(restwo > i)continue;
			if(restwo + mp[-1] < i)continue;
			int need = i-restwo;
			if(mp[-1] - need > (n/2 - (i+j)))continue;

			// ok
			ans[1] = one;
			ans[2] = two;
			ans[-1] =  (n/2 - (i+j)) - (mp[-1] - need);
			ans[0] = n/2 - (one + two + ans[-1]);
			output();
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
