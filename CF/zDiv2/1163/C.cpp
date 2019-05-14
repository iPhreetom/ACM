// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > v(n+1);
	for (int i=1; i<=n; i++){
		int x, y;
		cin >> x >> y;
		v[i] = make_pair(x, y);
	}

	map<pair<pair<int,int>, pair<int,int> >, int> mp;
	int num = 0;
	// zero down -> 0/0
	// zero up   -> 0/1
	// zero b    -> x1/0
	// com       -> 1e5,1e5
	const pair<int,int> cst = make_pair(112345,112345);

	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++) {
			int x1 = v[i].first;
			int x2 = v[j].first;
			int y1 = v[i].second;
			int y2 = v[j].second;

			int kup = y2 - y1;
			int kdown = x2 - x1;
			if (kdown == 0) {
				kup = 0;
				kdown = 0;
			}
			else {
				if (kup == 0) {
					kdown = 1;
				}
				else {
					int com = __gcd(kup,kdown);
					kup/=com;
					kdown/=com;
					if((kup < 0 && kdown < 0) || (kdown < 0)) {
						kup *= -1;
						kdown *= -1;
					}
				}
			}

			int bup = y1*(x2-x1) - x1*(y2-y1);
			int bdown = x2-x1;
			if (bdown == 0) {
				bup = x1;
				bdown = 0;
			}
			else {
				if (bup == 0) {
					bdown = 1;
				}
				else {
					int com = __gcd(bup,bdown);
					bup /= com;
					bdown /= com;
					if((bup < 0 && bdown < 0) || (bdown < 0)) {
						bup *= -1;
						bdown *= -1;
					}
				}
			}

			if(mp.count(make_pair(make_pair(kup,kdown),make_pair(bup,bdown))) == 0) {
				mp[make_pair(make_pair(kup,kdown),make_pair(bup,bdown))] = 1;
				mp[make_pair(make_pair(kup,kdown),cst)]++;
				num ++ ;
				// cout<<"1 = "<<x1<< "   " << y1 << endl;
				// cout<<"2 = "<<x2<< "   " << y2 << endl;
				// cout << endl;
			}
		}
	}

	int cnt = 0;
	int ans = 0;
	for (auto i : mp) {
		pair<pair<int,int>, pair<int,int>> key = i.first;
		if (key.second == cst) continue;
		ans += (num - mp[make_pair(key.first, cst)]);
	}
	cout << ans/2 << endl;
	return 0;
}
