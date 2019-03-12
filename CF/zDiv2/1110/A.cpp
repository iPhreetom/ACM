#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int b, k;
	cin >> b >> k;


	int sum = 0;
	vector<int> v(212345, 0);
	for (int i=1; i<=k; i++){
		cin >> v[i];
		sum += v[i];
	}

	if(b%2 == 1) {
		// no influence to the a
		if(sum % 2 == 1) {
			cout << "odd" << endl;
		}
		else {
			cout << "even" << endl;
		}
		// d
	}
	else {
		// b = 2
		if(v[k]%2 == 1) {
			cout << "odd" << endl;
		}
		else {
			cout << "even" << endl;
		}
	}


	return 0;
}
