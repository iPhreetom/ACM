// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int prefix[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a, b;
	cin >> a >> b;

	int sum = 0;

	if(b[0] == '1') prefix[0] = 1;
	for (int i=1; i<b.size(); i++){
		if(b[i] == '1') {
			prefix[i] = prefix[i-1] + 1;
		}
		else {
			prefix[i] = prefix[i-1];
		}
	}

	int dif = b.size() - a.size();

	for (int i=0; i<a.size(); i++){
		int one = prefix[i + dif] - prefix[i];
		if(a[i] == '0') {
			if(b[i] == '1') sum ++;
			sum += one;
		}
		else {
			if(b[i] == '0') sum ++;
			sum += dif - one;
		}
	}
	cout << sum << endl;
	return 0;
}
