#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int mod = 1000000007;
int a[212345];
int b[212345];
int sumzero;
int sumone;

int calone(int t){
	if(t == 1){
		return 1;
	}
	else{
		// right
		if(t % 2 == 1){
			return t/2 - 1;
		}
		else{

		}
	}
}

int calzero(int t){
	if(t == 1){
		return 0;
	}
	else{

	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;

		a[i] = calone(r);
		a[i] += mod;
		a[i] %= mod;
		a[i] -= calone(l);
		a[i] += mod;
		a[i] %= mod;

		b[i] = calzero(r);
		b[i] += mod;
		b[i] %= mod;
		b[i] -= calzero(l);
		b[i] += mod;
		b[i] %= mod;

		sumone += a[i];
		sumone %= mod;

		sumzero += b[i];
		sumzero %= mod;
	}
	for(int i=0;i<n;i++){

	}

	return 0;
}
