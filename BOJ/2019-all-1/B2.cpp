// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<char> v;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x,y;
	cin >> n >> x >> y;

	bool sw = 0;
	// if (x < y) swap(x,y),sw=1;
	v.push_back(12);
	int sumx = 0; // y pre val
	int sumy = 0; // x pre val

	while(sumx < y || sumy < x) {
		if ((sumx+1)*y > (sumy+1)*x) {
			sumy++;
			v.push_back(2);
		}
		else if((sumx+1)*y < (sumy+1)*x) {
			sumx++;
			v.push_back(1);
		}
		else {
			sumx++;
			sumy++;
			v.push_back(12);
			v.push_back(12);
		}
	}

	for (int i=0; i<n; i++){
		int tp;
		cin >> tp;
		tp %= (x+y);
		if (v[tp] == 12) cout << "Both" << endl;
		else if(v[tp] == 1) cout << (!sw?"Vanya":"Vova") << endl;
		else cout << (sw?"Vanya":"Vova") << endl;
	}
	return 0;
}
