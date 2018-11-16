#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[1123456];
bool vis[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,c;
		cin>>n>>c;
		for (int i=1; i<=n; i++){
			int l,r;
			cin>>l>>r;
			a[i] = r-l;
		}

		bool ended=0;
		bool can = 1;
		int l=1,r=1;
		while(can && !ended){
			c -= a[r];
			if(c >= 0){
				if(r-l+1 == n){ended=1;break;}
				r++;
				if(r > n)r%=n;
			}
			else{
				while((l <= r || ) && c < 0){
					c += a[l];
					l++;
				}
				r++;
			}
		}
	}
	return 0;
}
//
3 0
1 2 3
