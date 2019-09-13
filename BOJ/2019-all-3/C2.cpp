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
	unordered_map<int,int> mpa,mpb;
	int sumb = 0;
	for (int i=0; i<n; i++) cin >> a[i],mpa[a[i]]++;;
	for (int i=0; i<m; i++) cin >> b[i],mpb[b[i]]++, sumb+=b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	if (a[0] >= b.back()) {cout << 0 << endl; return 0;}

	vector<int> com = a;
	for (int i=0; i<b.size(); i++) com.push_back(b[i]);
	sort(com.begin(),com.end());
	com.erase(unique(com.begin(),com.end()),com.end());
	int mn = 1e18;
	vector<int> prea,preb;
	vector<int> cnta,cntb;
	for (int i=0; i<com.size(); i++){
		if (binary_search(a.begin(),a.end(),com[i])) {
			prea.push_back(com[i]*mpa[com[i]]+(prea.empty()?0:prea.back()));
			cnta.push_back(mpa[com[i]]+(cnta.empty()?0:cnta.back()));
		}
		else {
			prea.push_back((prea.empty()?0:prea.back()));
			cnta.push_back((cnta.empty()?0:cnta.back()));
		}
		if (binary_search(b.begin(),b.end(),com[i])) {
			preb.push_back(com[i]*mpb[com[i]]+(preb.empty()?0:preb.back()));
			cntb.push_back(mpb[com[i]]+(cntb.empty()?0:cntb.back()));
		}
		else {
			preb.push_back((preb.empty()?0:preb.back()));
			cntb.push_back((cntb.empty()?0:cntb.back()));
		}
		mn = min(mn, (i==0?0:cnta[i-1])*com[i]-(i==0?0:prea[i-1]) + (sumb-preb[i])-(m-cntb[i])*com[i]);
	}
	cout << mn << endl;
	return 0;
}
