#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> v;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k,m;
	cin >> n >> k >> m;

	int sum = 0;
	for (int i=1; i<=n; i++){
		int t;
		cin >> t;
		v.push_back(t);
		sum += t;
	}
	double ans = (double)sum/n;

	sort(v.rbegin(),v.rend());

	while(m > 0 && k > 0) {
		if(v[0] > v.back()) {
			sum -= v.back();
			v.pop_back();
			m --;
		}
		else {
			if(k > 0){
				v[0]++;
				k --;
				sum++;
			}
			m --;
		}
	}

	double up = sum;
	double down = v.size();
	cout << fixed << setprecision(12) << up/down << endl;

	return 0;
}
