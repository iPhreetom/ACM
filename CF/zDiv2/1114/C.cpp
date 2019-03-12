#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> v;
vector<int> cnt;

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,b;
	cin >> n >> b;

	int t = b;
	int lim = sqrt(b);
	for (int i=2; i<=lim; i++) {
		if(t/i*i == t) {
			v.push_back(i);
			int c = 0;
			while(t/i*i == t){
				c++;
				t/=i;
			}
			cnt.push_back(c);
		}
		if(t == 1)break;
	}
	if(t!=1){
		v.push_back(t);
		cnt.push_back(1);
	}

	int sum = 1e18;
	for (int i=0; i<v.size(); i++) {
		int now = 0;
		int t = n;
		// cout << "v[i] = " << v[i] << endl;
		// cout << "cnt[i] = " << cnt[i] << endl;
		while(t>0) {
			now += t/v[i];
			t/=v[i];
		}
		sum = min(sum,now/cnt[i]);
	}

	cout << sum << endl;
	return 0;
}
