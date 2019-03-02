#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	multiset<int> s;
	for (int i=1; i<=n; i++){
	    int t;
		cin>>t;
		s.insert(t);
	}

	int mx = *s.rbegin();
	for (int i=1; i<=sqrt(mx); i++){
		if(mx % i == 0) {
			if(i == mx/i) {
				s.erase(s.find(i));
			}
			else {
				s.erase(s.find(i));
				s.erase(s.find(mx/i));
			}
		}
	}
	cout << mx << ' ' << *s.rbegin()<<endl;

	return 0;
}
