// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[2123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1; i<=n; i++){
	    cin>>a[i];
	}
	int sum = 0;
	int x,f;
	cin>>x>>f;
	for (int i=1; i<=n; i++){
		if(a[i] > x){
			int ci = a[i]/(f+x);
			a[i] -= ci*(f+x);

			if(a[i] > x)ci++;
			sum += ci*f;
		}
	}
	cout<<sum<<endl;
	return 0;
}
