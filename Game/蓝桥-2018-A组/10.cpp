#include<bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	double sum;
	cin >> n >> sum;

	vector<double> v(n);
	for (int i=0; i<n; i++) {
		int t;
		cin >> t;
		v[i] = t;
	}

	sort(v.begin(),v.end());
	double eq = sum/n;
	double ans = 0;
	double more = 0;

	for (int i=0; i<n; i++) {
		if(v[i] <= eq) {
			more += (eq-v[i]);
			ans += (v[i]-eq)*(v[i]-eq);
		}
		else {
			int res = n-i;
			double jun = more/res;
			if(jun <= v[i]-eq) {
				for (int j=0; j<res; j++) {
					ans += jun*jun;
				}
				break;
			}
			else {
				double dif = min(more, v[i]-eq);
				more -= dif;
				ans += dif*dif;
			}
		}
	}

	ans /= n;
	ans = sqrt(ans);

	cout << fixed << setprecision(4) << ans << endl;
}
