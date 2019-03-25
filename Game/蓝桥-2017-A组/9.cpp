#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;
int n, k;

inline bool check(int val) {
	int sum = 0;
	for (int i=0; i<n; i++) {
		sum += (v[i].first/val) * (v[i].second/val);
	}
	if(sum >= k)return 1;
	else return 0;
}

int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int h,w;
		cin >> h >> w;
		v.push_back(make_pair(h,w));
	}
	int l = 1;
	int r = 100001;
	while (l + 1 < r) {
		int mid = (l+r)/2;
		if(check(mid))l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}
