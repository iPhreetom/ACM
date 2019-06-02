// fyt
#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin >> t;

	while (t--) {
		int index = 0;
		for (int i=1; i<=90; i++){
			int d;
			cin >> d;
			cout << ++index << ' ' << 100 << endl;
			index %= 18
			;
		}

		int d;
		cin >> d;
		cout << 19 << ' ' << 0 << endl;
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i=0; i<v.size(); i++){
			cin >> v[i];
		}

		cin >> d;
		cout << 20 << ' ' << 0 << endl;// 92
		int m;
		cin >> m;
		vector<int> v2(m);
		for (int i=0; i<v2.size(); i++){
			cin >> v2[i];
		}

		if (n >= m) {
			for (int i=93;i<=99;i++) {
				cin >> d;
				cout << 19 << ' ' << 100 << endl;
			}
			cin >> d;
			cout << 20 << ' ' << 100 << endl;
		}
		else {
			for (int i=93;i<=99;i++) {
				cin >> d;
				cout << 20 << ' ' << 100 << endl;
			}
			cin >> d;
			cout << 19 << ' ' << 100 << endl;
		}
	}
	return 0;
}
