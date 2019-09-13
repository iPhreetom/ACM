// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node {
	static const int maxn = 6e5+100;
	int node[maxn*24+100][2];
	int cnt[maxn*24+100];
	int val[maxn*24+100];
	int tot = 1;

	inline void insert(int x) {
		int p = 0;
		for (int i=23; i>=0; i--) {
			bool d = ((x>>i)&1);
			if (!node[p][d]) node[p][d]=tot++;
			p = node[p][d];
			cnt[p]++;
		}
		val[p] = x;
	}

	inline bool find(int x) {
		int p = 0;
		for (int i=23; i>=0; i--) {
			bool d = ((x>>i)&1);
			if (!node[p][d]) return 0;
			p = node[p][d];
			cnt[p]++;
		}
		return 1;
	}

	inline void erase(int x) {
		int p = 0;
		for (int i=23; i>=0; i--) {
			bool d = ((x>>i)&1);
			p = node[p][d];
			cnt[p]--;
		}
	}
}tr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	tr.tot = 1;
	vector<int> v(n);
	for (int i=0; i<n; i++){
		cin >> v[i];
		tr.insert(v[i]);
	}

	bool f = 1;
	for (int i=0; i<n; i++) {
		// cout<<"bitset<32>(v[i]) = "<<bitset<32>(v[i])<<endl;
		unsigned int rt = v[i];
		rt = (~rt);
		// cout<<"bitset<32>(rt) = "<<bitset<32>(rt)<<endl;
		rt %= (int)pow(2,23);

		int r = rt;
		int val = -1;
		// cout<<"bitset<32>(r) = "<<bitset<32>(r)<<endl;
		for (int j=23; j>=0 ; j--) {
			if (tr.find(r)) {
				val = r;
				break;
			}
			if ((r>>j)&1) r = (r^(1<<j));
			// cout<<"r = "<<r<<endl
		}

		if (val != -1) {
			if (f) cout << val, f = 0;
			else cout << ' ' << val;
		}
		else {
			val = -1;
			if (f) cout << val, f = 0;
			else cout << ' ' << val;
		}
	}

	cout << endl;
	return 0;
}
