#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	double me = 0;
	vector<double> v(n-1, 0);
	cin >> me;
	for (int i=0; i<n-1; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(),v.rend());
	v.push_back(me);

	int num = 2;
	while(num*2 <= n) {
		num*=2;
	}

	int res = n-num;
	vector<double> ans(n, 1);
	if(res != 0) {
		num*=2;
		for (int i=2*res; i<v.size(); i+=2) {
			v.push_back(0);
			ans.push_back(0);
			for (int j=v.size()-1; j>=i; j--) {
				v[j] = v[j-1];
				ans[j] = ans[j-1];
			}
			ans[i] = 1;
			v[i] = 0;
		}
	}

	v.push_back(0);
	ans.push_back(0);
	for (int i=v.size()-1;i>0;i--) {
		v[i] = v[i-1];
		ans[i] = ans[i-1];
	}


	// for (int i=0; i<v.size(); i++) {
	//     cout << v[i] << ' ';
	// }
	// cout << endl;
	// for (int i=0; i<ans.size(); i++) {
	//     cout << ans[i] << ' ';
	// }
	// cout << endl;




	int cen = log2(num);
	int len = 1;
	ans[0] = 0;
	v[0] = 0;

	while(cen--) {
		bool bk = 1;
		vector<double> ans2 = ans;
		for (int i=0; i<num/len; i++) {
			for (int j=1; j<=len; j++) {
				int p = i*len + j;
				double tp = 0;
				// cout << "p = " << p << endl;
				if (bk) {
					for (int k=1;k<=len;k++) {
						int q = (i+1)*len + k;
						if(v[p] + v[q] == 0)break;
						tp += v[p]/ ((v[p]+v[q]))*ans2[p]*ans2[q];
					}
				}
				else {
					for (int k=1;k<=len;k++) {
						int q = (i-1)*len + k;
						if(v[p] + v[q] == 0)break;
						tp += v[p]/ ((v[p]+v[q]))*ans2[p]*ans2[q];
					}
				}
				ans[p] = tp;
			}
			bk = !bk;
		}
		len*=2;
		// cout << "ans.size() = " << ans.size() << endl;
		// for (int i=0; i<v.size(); i++) {
		//     cout << v[i] << ' ';
		// }
		// cout << endl;
		// for (int i=0; i<ans.size(); i++) {
		//     cout << ans[i] << ' ';
		// }
		// cout << endl;
	}

	cout << fixed << setprecision(9) << ans.back() << endl;
	return 0;
}
