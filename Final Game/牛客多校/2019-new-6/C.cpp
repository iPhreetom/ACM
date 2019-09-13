// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vector<string> s;
	s.push_back("aaaaabbbbb");
	s.push_back("aaaabb");
	s.push_back("bb");
	sort(s.begin(),s.end());
	for (int i=0; i<s.size(); i++){
cout << s[i] << endl;
	}
	return 0;
}
