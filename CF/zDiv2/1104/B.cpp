// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;

	int cnt = 0;
	string p;
	p.push_back('#');
	p.push_back(s[0]);
	for (int i=1; i<s.size(); i++){
		if(s[i] == p.back()) {
			cnt++;
			p.pop_back();
		}
		else {
			p.push_back(s[i]);
		}
	}
	if(cnt % 2){
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	return 0;
}
