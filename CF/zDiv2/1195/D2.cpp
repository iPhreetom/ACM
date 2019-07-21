// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	int sum = 0;
	int mod = 998244353;
	cin >> n;
	vector<int> cnt(11);
	vector<string> v(n);
	for (int i=0; i<n; i++){
		cin >> v[i];
		cnt[v[i].size()]++;
	}

	for (int i=0; i<n; i++){
		for (int k=1; k<=10; k++) {
			int temp1 = 0;
			int temp2 = 0;
			if (cnt[k] == 0) continue;

			if (k >= v[i].size()) {
				for (int j=0; j<v[i].size(); j++){
					temp1 *= 100;
					temp1 += v[i][j]-'0';
					if (temp1 > mod) temp1 %= mod;

					temp2 += v[i][j]-'0';
					if (j != v[i].size()-1)temp2 *= 100;
					else temp2 *= 10;
					if (temp2 > mod) temp2 %= mod;
				}
				temp1 *= cnt[k];
				if (temp1 > mod) temp1 %= mod;
				temp2 *= cnt[k];
				if (temp2 > mod) temp2 %= mod;
				sum += temp1;
				sum += temp2;
			}
			else {
				int num = 0;
				int dif = v[i].size()-k;
				for (int j=0; j<v[i].size(); j++){
					if (num >= dif) temp1 *= 100;
					else temp1 *= 10;
					temp1 += v[i][j]-'0';
					if (temp1 > mod) temp1 %= mod;

					num++;
					temp2 += v[i][j]-'0';
					if (num > dif && j!=v[i].size()-1) temp2 *= 100;
					else temp2 *= 10;
					if (temp2 > mod) temp2 %= mod;
				}
				// cout<<"temp1 = "<<temp1<<endl;
				// cout<<"temp2 = "<<temp2<<endl;
				temp1 *= cnt[k];
				if (temp1 > mod) temp1 %= mod;
				temp2 *= cnt[k];
				if (temp2 > mod) temp2 %= mod;
				sum += temp1;
				sum += temp2;
			}
		}
	}
	sum %= mod;
	cout << sum << endl;
	return 0;
}
