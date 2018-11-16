// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 112345;

int a[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,l;
	cin>>n>>m>>l;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}

	int last = 1;
	bool nonc = 1;
	int ans = 0;
	for (int i=1; i<=n; i++){
		if(nonc){
			if(a[i] > l){
				nonc = 0;
				ans++;
			}
		}
		else{
			if(a[i] <= l){
				nonc = 1;
			}
		}
	}
	// cout<<"ans = "<<ans<<endl;


	while(m--){
		int t;
		cin>>t;
		if(t == 0){
			cout<<ans<<endl;
		}
		if(t == 1){
			int p,d;
			cin>>p>>d;

			if(a[p] <= l){
				a[p] += d;
				if(a[p] > l){

					if(a[p-1] <= l && a[p+1] <=l){
						ans++;
					}

					if(a[p-1] > l && a[p+1] > l){
						ans--;
					}

				}
			}
		}
	}
	return 0;
}
