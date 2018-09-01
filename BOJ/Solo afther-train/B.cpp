// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int a[5005];
const int maxn = 11234567890;
int ans = 0;
int n;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++){
	    cin>>a[i];
		if(a[i] >= n){
			ans++;
			a[i]= 2*maxn;
		}
	}
	while(1){
		bool findit = 0;
		for (int i=1; i<=n; i++){
			if(a[i] != 0 && a[i] < maxn){
				findit = 1;

				int j;
				int len = 1;
				for (j=i+1; j<=n; j++){
					if(a[j] == 0){
						break;
					}
					if(a[j] < maxn)len++;
				}
				j--;



				bool del = 0;
				int mn = maxn;
				int cnt = 0;
				for(int k = i;k<=j;k++){
					if(a[k] >= len && a[k]<maxn){
						a[k] = maxn;
						ans++;
						del = 1;
					}
					else{
						mn = min(mn,a[k]);
						if(a[k]<maxn)cnt++;
					}
				}


				if(!del){
					if(mn <= cnt){
						ans+=mn;
						for(int k = i;k<=j;k++){
							a[k] -= mn;
						}
					}
					else{
						ans += cnt;
						for(int k = i;k<=j;k++){
							a[k] = 2*maxn;
						}
					}
				}



				break;
			}
		}
		// cout<<"ans = "<<ans<<endl;
		// for (int i=0; i<n; i++){
		//     cout<<a[i+1]<<' ';
		// }cout<<endl;

		if(!findit){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
