// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int one = 0;
	int zero = 0;
	int oz = 0;
	int zo = 0;
	int f = 2e9;
	map<int,int> mp;


	for (int i=1; i<=(int)sqrt(f); i++){
		mp[(i+1)*i/2] = i+1;
	}
	mp[0] = 0;
	if (a == 0 || d == 0) {
		if (a == 0 && d == 0) {
			if (c != 0 || b != 0) {
				if (b == 1 && c == 0) {
					cout << "01" << endl;
				}
 				else if (b == 0 && c == 1) {
					cout << "10" << endl;
				}
				else cout << "impossible" << endl;
			}
			else {
				cout << "1" << endl;
			}
			return 0;
		}
		else {
			if (b != 0 || c != 0) {
				mp[0] = 1;
			}
		}
	}

	if (mp.count(a) == 0 || mp.count(d) == 0) {
		cout << "impossible" << endl;
		return 0;
	}
	zero = mp[a];
	one = mp[d];

	deque<int> p(one,0);
	zo = 0; // b
	oz = one*zero; // c

	if (b+c != one*zero) {
		cout << "impossible" << endl;
		return 0;
	}

	for (int i=0; i<p.size(); i++){
		if (oz > c) {
			if (oz-c >= zero) {
				p[i] = zero;
				oz -= zero;
				zo += zero;
			}
			else {
				int dif = oz-c;
				p[i] = dif;
				oz -= dif;
				zo += dif;
				break;
			}
		}
	}

	sort(p.begin(),p.end());
	string ans;
	for (int i=0; i<=zero; i++){
		while (!p.empty() && p.front()==i) {
			ans.push_back('1');
			p.pop_front();
		}
		if (i!=zero) ans.push_back('0');
	}
	cout << ans << endl;
	return 0;
}
