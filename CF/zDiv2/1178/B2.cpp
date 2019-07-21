// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	// ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;

	while(!s.empty() && s.back() == 'o') s.pop_back();
	if (s.empty()) {
		cout << 0 << endl;
		return 0;
	}

	reverse(s.begin(),s.end());
	s.push_back('-');

	vector<int> v;
	int cnt = 1;
	for (int i=1; i<s.size(); i++){
		if (s[i] == s[i-1]) cnt++;
		else {
			v.push_back(cnt);
			cnt = 1;
		}
	}

	int len = v.size();
	vector<int> w;
	vector<int> o;
	w.push_back(0);
	o.push_back(0);

	// for (int i=0; i<v.size(); i++){
	//     cout<<v[i]<<' ';
	// }cout<<endl;
	bool f = 0;
	for (int i=0; i<len; i++){
		if (i % 2 == 1) {
			if (f) {
				o.back() += v[i];
				f = 0;
			}
			else o.push_back(v[i]);
		}
		else { // w
			if (v[i] == 1) {
				f = 1;
			}
			else w.push_back(v[i]-1);
		}
	}

	if (w.size() <= 2 || o.size() <= 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> pre(w.size());
	pre[0] = w[0];
	for (int i=1; i<w.size(); i++){
		pre[i] = w[i] + pre[i-1];
	}
	int ans = 0;
	for (int i=1; i<w.size()&&i<o.size(); i++){
		ans += pre[i]*o[i]*(pre.back()-pre[i]);
	}
	// for (int i=0; i<w.size(); i++){
	//     cout<<w[i]<<' ';
	// }cout<<endl;
	// for (int i=0; i<o.size(); i++){
	//     cout<<o[i]<<' ';
	// }cout<<endl;
	// for (int i=0; i<pre.size(); i++){
	//     cout<<pre[i]<<' ';
	// }cout<<endl;
	cout << ans << endl;
	return 0;
}
