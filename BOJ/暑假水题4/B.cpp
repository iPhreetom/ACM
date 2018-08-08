#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string ans[9123];
string p[10];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n>>s;

	s = s+s;
	for(int i=0;i<=9;i++){
		p[i] = s;
		for (int j=0; j<2*n; j++){
		    p[i][j] = s[j]+i>'9'?s[j]+i-10:s[j]+i;
		}
	}

	// cout<<s<<endl;
	string out = s.substr(0,n);
	// cout<<out<<endl;
	for (int i=0; i<=9; i++){
	    for (int j=0; j<=n; j++){
			// cout<<p[i].substr(j,n)<<endl;
	        out = min(p[i].substr(j,n),out);
	    }
	}
	cout<<out<<endl;
	return 0;
}
