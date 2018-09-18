// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int num[26];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for (int i=0; i<s.size(); i++){
	    num[s[i]-'A']++;
	}
	int max = 122222;
	for (int i=0; i<k; i++){
	    max = min(num[i],max);
	}
	cout<<max*k<<endl;
	return 0;
}
