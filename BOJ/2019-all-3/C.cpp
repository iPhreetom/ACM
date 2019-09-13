// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i<m; i++){
		cin >> b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	unordered_map<int,int> mpa,mpb;
	for (int i=0; i<n; i++){
	    mpa[a[i]]++;
	}
	for (int i=0; i<m; i++){
	    mpb[b[i]]++;
	}
	a.erase(unique(a.begin(),a.end()),a.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	if (a[0] >= b.back()) {cout << 0 << endl; return 0;}

	vector<int> prea(a.size()),preb(b.size());
	prea.push_back(a[0]*mpa[a[0]]);
	preb.push_back(b[0]*mpb[b[0]]);
	for (int i=1; i<a.size(); i++){
		prea.push_back(prea.back()+a[i]*mpa[i]);
	}
	int sumb = b[0]*mpb[b[0]];
	for (int i=1; i<b.size(); i++){
		preb.push_back(preb.back()+b[i]*mpb[i]);
		sumb += b[i]*mpb[i];
	}

	// the value
	set<int> s;
	for (int i=0; i<a.size(); i++){
		s.insert(a[i]);
	}
	for (int j=0; j<b.size(); j++){
		s.insert(b[j]);
	}
	int mn = 1e18;
	for (auto i:s) {
		int indexa = lower_bound(a.begin(),a.end(),i)-a.begin();
		int indexb = upper_bound(b.begin(),b.end(),i)-b.begin();
		mn = min(mn,prea[indexa]-preb[indexb]+sumb);
		cout<<"i = "<<i<<endl;
		cout<<"indexa = "<<indexa<<endl;
		cout<<"indexb = "<<indexb<<endl;
	}
	cout << mn << endl;
	return 0;
}
