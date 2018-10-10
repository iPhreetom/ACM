#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

set<int> s;

int f(int n){
	int sum = 0;
	while(n){
		sum += (n%10)*(n%10);
		n /= 10;
	}
	return sum;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;


	bool ok = 0;
	while(1){
		if(s.count(n) == 0){
			s.insert(n);
		}
		else{
			break;
		}
		n = f(n);
	}
	if(s.count(1) != 0){
		cout<<"HAPPY"<<endl;
	}
	else{
		cout<<"UNHAPPY"<<endl;
	}
	return 0;
}
