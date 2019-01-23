#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double start = 6300;
	double up = 0.03057/365;

	for (int i=1; i<=365; i++){
		start = start*(1+up);
	}

	cout<<"start = "<<(long long)start<<endl;
	cout<<"start-6300 = "<<(long long)start-6300<<endl;

	cout<<start/6300<<endl;
	return 0;
}
