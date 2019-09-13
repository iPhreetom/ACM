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
	while(n--){
		vector<int> v;
		int len = 0;
		for (int i=0; i<16; i++){
		    int t;
			cin >>t;
			v.push_back(t);
			if (t == 0) len = i/4;
		}
		len = 3-len;

		bool can = 1;
		int sum = 0;
		for (int i=0; i<16; i++){
			if (v[i] == 0) continue;
			for (int j=0; j<i; j++){
				if (v[j] == 0) continue;
				if (v[j] > v[i]) {
					sum++;
				}
			}
		}
		if (sum % 2 == len%2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
