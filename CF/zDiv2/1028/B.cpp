// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a,b;
	//    999
	// 999001
	for (int i=0; i<1000; i++){
		a.push_back('9');
	}
	for (int i=0; i<1000; i++){
		b.push_back('9');
	}
	for (int i=0; i<999; i++){
		b.push_back('0');
	}
	b.push_back('1');
	cout<<a<<endl;
	cout<<b<<endl;

	return 0;
}
