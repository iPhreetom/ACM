#include<bits/stdc++.h>
#define int long long
using namespace std;


int n,m;
int ans[212345];
int a[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;

	int l = 1;
	int r = n;
	int num = n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(l <= r){
		ans[l]=1;
		for(int i=0;i<a[l]-a[l-1]-1 && l<r;i++){
			ans[r--] = num--;
		}
		l++;

	}

	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}cout<<endl;
	return 0;
}
