// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	string t;

	cin>>a;

	set<char> s;
	for (int i=1; i<=5; i++){
		string tp;
		cin>>tp;
		t += tp;
	}
	for (int i=0; i<a.size(); i++){
		s.insert(a[i]);
	}
	for (int i=0; i<t.size(); i++){
		if(s.count(t[i]) != 0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
