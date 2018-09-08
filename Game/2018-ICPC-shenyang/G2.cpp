#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int exgcd(int a,int b,int &x,int &y){
	int result = a;
	if(b == 0){
		x = 1;
		y = 0;
	}
	else{
		result = exgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}
	return result;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int x,y,mod;
	mod = 1e9+7;
	exgcd(2,mod,x,y);
	x += mod;
	x%=mod;
	cout<<x<<endl;
	return 0;
}
