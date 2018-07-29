#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;

	int ans = 0;

	ans += n/100;
	n %=100;

	ans+=n/20;
	n %=20;

	ans += n/10;
	n %= 10;

	ans += n/5;
	n %= 5;

	ans += n/1;
	cout<<ans<<endl;
	return 0;
}
