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

	for (int i=0; i<n; i++){
	    if(a[i] == '1' && b[i] == '1') mp[2]++;
		else if(a[i] == '1' && b[i] == '0') mp[1]++;
		else if(a[i] == '0' && b[i] == '0') mp[0]++;
		else mp[-1]++;
	}

	cout<<"mp[-1] = "<<mp[-1]<<endl;
	cout<<"mp[0] = "<<mp[0]<<endl;
	cout<<"mp[1] = "<<mp[1]<<endl;
	cout<<"mp[2] = "<<mp[2]<<endl;
	// cal the 1
	ans[1] = min(mp[1],mp[-1]);
	mp[1] -= ans[1];
	mp[-1] -= ans[1];

	if (mp[1] == mp[-1]) {
		// zero mp[1] == mp[-1] == 0
		if(mp[2] % 2 == 1) {
			if(ans[1] > 0) {
				ans[1]--;
				ans[2]++;

				mp[1]++;
				mp[2]--;
				ans[2] += mp[2]/2;
				ans[0] += (mp[0] + 1)/2;
			}
			else {
				cout << -1 << endl;
				return 0;
			}
		}
		else {
			ans[2] = mp[2]/2;
			ans[0] = mp[0]/2;
		}
	}
	else if(mp[1] > mp[-1]) {
		// can't
		int dif = mp[1] - mp[-1];
		int res = n - ans[1];
		if(mp[1] > res) {
			cout << -1 << endl;
			return 0;
		}
		else {
			int add = min(mp[1], mp[2]);
			ans[1] += add;
			mp[1] -= add;
			mp[2] -= add;

			if(mp[1] == 0) {
				// zero de geshu
				if(mp[2] % 2 == 0) {
					ans[2] += mp[2]/2;
					ans[0] += mp[0]/2;
				}
				else {
					if(ans[1] == 0) {
						cout << -1 << endl;
						return 0;
					}
					else {
						ans[1]--;
						ans[2]++;

						mp[2]--;
						mp[1]++;
						ans[2] += mp[2]/2;
						ans[0] += (mp[0]+1)/2;
					}
				}
			}
			else {
				// copy
				// mp[2] == 0
				// and mp[1] >= 0
				if(mp[0] < mp[1]) {
					cout << -1 << endl;
					return 0;
				}
				else {
					ans[0] += (mp[0] + mp[1])/2;
				}
			}
		}
	}
	else if(mp[-1] > mp[1]) {
		// can't
		int dif = abs(mp[1] - mp[-1]);
		int res = n - ans[-1];
		if(mp[-1] > res) {
			cout << -1 << endl;
			return 0;
		}
		else {
			// 
		}
	}

	vector<int> v;
	for (int i=0; i<n; i++){
		if(a[i] == '1' && b[i] == '1' && ans[2] > 0) v.push_back(i+1);
		else if(a[i] == '1' && b[i] == '0' && ans[1] > 0) v.push_back(i+1);
		else if(a[i] == '0' && b[i] == '0' && ans[0] > 0) v.push_back(i+1);
		else if(ans[-1] > 0) v.push_back(i+1);
	}
	for (int i=0; i<v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;
	return 0;
}
