// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	// char ch = s[0];

	for(int i=1;i<s.size();i++){
		if(s[i] != s[i-1]){
			cout<<"YES"<<endl;
			cout<<s.substr(i-1,2)<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
