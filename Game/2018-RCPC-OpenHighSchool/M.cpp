// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	int sum = 0;
	int mx = 0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i] != a[i-1]){
			sum++;
		}
		else{
			mx = max(sum,mx);
			sum = 1;
		}
	}
	mx = max(mx,sum);
	cout<<mx<<endl;
	return 0;
}
