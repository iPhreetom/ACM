// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int a[12012];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool ok = 0;
	for (auto i:s){
	    a[i]++;
		if(a[i] == 2)ok = 1;
	}
	if(s.size() == 1)ok=1;
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
