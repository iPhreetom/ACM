#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(212345, 0);
	vector<int> b(212345, 0);
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	for (int i=1; i<=n; i++){
		cin >> b[i];
	}
	vector<int> s;
	vector<int> t;
	for (int i=2; i<=n; i++){
		s.push_back(a[i]-a[i-1]);
		t.push_back(b[i]-b[i-1]);
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());

	if(a[1] != b[1] || a[n]!=b[n]){
		cout << "No" << endl;
		return 0;
	}
	for (int i=0; i<s.size(); i++){
		if(s[i] != t[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
