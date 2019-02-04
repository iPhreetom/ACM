// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

set<int> s;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	if(n % 2 == 0){
		s.insert(2+n/2);
	}

	for (int i=1; i<=sqrt(n); i++){
		if(n % i == 0){
			int tp = 0;
			int k = __gcd(n,i);
			int times = (n-1)/k;
			int last = 1ll + k*times;
			tp = (1ll+last)	*(times+1ll)/2ll;

			s.insert(tp);
			if(1) {
				int tp = 0;
				int k = __gcd(n,n/i);
				int times = (n-1)/k;
				int last = 1ll + k*times;
				tp = (1ll+last)	*(times+1ll)/2ll;

				s.insert(tp);
			}
		}
	}

	bool f = 0;
	for(auto i:s){
		if(f == 0){
			f = 1;
			cout<<i;
		}
		else{
			cout<<' '<<i;
		}
	}
	cout<<endl;
	return 0;
}
// 1 2 3 6
// 1 2 4 8 16
