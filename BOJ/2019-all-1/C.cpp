// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int n;
	cin >> n;

	vector<int> v(s.size());
	int base = 1;
	int sum = 0;
	for (int i=s.size()-1; i>=0; i--){
		v[i] = (s[i]-'0')*base%n;
		sum += v[i];
		sum %= n;

		base *= 10;
		base %= n;
	}

	int mn = sum;
	int base2 = 1;
	s.push_back('0');
	for (int i=0; i<s.size()-1; i++){
		sum = (sum - v[i]*base2%n + n)%n;

		sum *= 10;
		sum %= n;
		sum = (sum+(s[i]-'0'))%n;

		if (s[i+1] != '0') {
			mn = min(sum,mn);
		}
		base2 *= 10;
		base2 %= n;
	}
	cout << mn << endl;
	return 0;
}
