#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[212345];
int lis[33];

void init(){
	int t = 1;
	for (int i=0; i<=32; i++){
	    lis[i] = pow(2,i);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	init();
	while(tt--){
		int n;
		int mx = 0;
		int ans[33];
		memset(ans,0,sizeof(ans));
		cin>>n;
		for (int i=1; i<=n; i++){
			cin>>a[i];
			for (int j=0; j<=32; j++){
			    if(a[i] <= lis[j]){
					if(a[i] == lis[j])ans[j]++;
					else ans[j-1]++;
					break;
				}
			}
		}
		for (int i=0; i<33; i++){
		    mx =max(mx,ans[i]);
		}
		cout<<mx<<'\n';
	}
	return 0;
}
