// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 212345;
int sum[maxn];
int a[maxn];

const int mod = 1e9+7;
int getsum(int l,int r){

}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;

	string s;
	cin>>s;

	for (int i=0; i<s.size(); i++){
		a[i+1] = s[i]-'0';
		sum[i+1] = sum[i] + a[i+1];
	}

	while(q--){
		int l,r;
		cin>>l>>r;
		int cnt = sum[r] - sum[l-1];

	}

	return 0;
}
