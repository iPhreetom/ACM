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
	vector<int> v(n);
	vector<int> ans;
	ans.push_back(1);
	cin >> v[0];
	int sum = v[0];
	int all = v[0];


	for (int i=1; i<n; i++){
		cin >> v[i];
		all += v[i];
		if (v[i]*2 <= v[0]) {
			sum += v[i];
			ans.push_back(i+1);
		}
	}

	if (sum*2 <= all){
		cout << 0 << endl;
		return 0;
	}

	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++){
		cout << ans[i] << ' ';
	}cout << endl;



	return 0;
}
