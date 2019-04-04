#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int findit(vector<int> a) {
	if(is_sorted(a.begin(),a.end())) {
		return a.size();
	}
	else {
		vector<int> lt,rt;
		for (int i=0; i<a.size()/2; i++) {
		    lt.push_back(a[i]);
		}
		for (int i=a.size()/2; i<a.size(); i++) {
		    rt.push_back(a[i]);
		}
		return max(findit(lt),findit(rt));
	}
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> a;
	for (int i=0; i<n; i++) {
	    int t;
		cin >> t;
		a.push_back(t);
	}

	cout << findit(a) << endl;
	return 0;
}
