// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i=1; i<=n; i++){
		v.push_back(i);
	}
	for (int i=0; i<v.size(); i++){
	    cout<<v[i]<<' ';
	}cout<<endl;
	while(next_permutation(v.begin(),v.end())) {
		for (int i=0; i<v.size(); i++){
		    cout<<v[i]<<' ';
		}cout<<endl;
	}
	return 0;
}
