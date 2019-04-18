// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

// iterator lower_bound( const key_type &key ): 返回一个迭代器，指向键值>= key的第一个元素。
// iterator upper_bound( const key_type &key ):返回一个迭代器，指向键值> key的第一个元素。

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> s(n);
	for (int i=0; i<n; i++){
		cin >> s[i];
	}

	sort(s.begin(),s.end());
	vector<int>::iterator iter = unique(s.begin(),s.end());
	s.erase(iter,s.end());
	n = s.size();
	sort(s.begin(),s.end());

	if(n == 1) {
		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			int len = r-l+1;
			cout << len << endl;
		}
	}
	else {
		vector<int> now;
		for (int i=1; i<s.size(); i++){
			now.push_back(s[i]-s[i-1]);
		}
		sort(now.begin(),now.end());
		vector<int> pre(now.size()+1,0);
		for (int i=1; i<=now.size(); i++){
			pre[i] = pre[i-1] + now[i-1];
		}

		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			int len = r-l+1;
			// now is segment
			int num = lower_bound(now.begin(),now.end(),len)-now.begin();
			int numcan = n - num;
			int ans = numcan * len;
			ans += pre[num];
			cout << ans << endl;
		}
	}

	return 0;
}
