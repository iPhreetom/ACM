#include<bits/stdc++.h>
#define int long long
#define double long double
#define make(a,b) make_pair(a,b)
using namespace std;


vector<int> arr;
vector<int> ans;
map<int,int> mp;

int n,k;


signed main(){
	cin>>n>>k;
	int all = k;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;	
		all = __gcd(all, t);
	}
	vector<int> res;
	for (int i = 0; i < k; i += all) res.push_back(i);
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) printf("%lld ", res[i]);
	cout << endl;
	return 0;
}
