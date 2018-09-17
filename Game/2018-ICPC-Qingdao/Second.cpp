#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e6+5;
int al[maxn];
int ar[maxn];


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int a,b,c,d,v,t;
		cin>>a>>b>>c>>d>>v>>t;
		if(a <= v || c <= v){
			int ca = t/a +1;
			int cc = t/c +1;
			int ans = ca*b+cc*d;
			ans--;
			cout<<ans<<endl;
		}
		else{
			int ca = t/a +1;
			int cc = t/c +1;
			if(a == c){
				cout<<(ca)*(b+d-1)<<endl;
			}
			else{
				// memset(al,0,sizeof(al));
				// memset(ar,0,sizeof(ar));
				int l=a,r=c;
				int lt = 0;
				// int ans = b+d-1;
				int il=0;
				int ir=0;
				al[il] = b-1;
				ar[ir] = d;

				while(l!=r){
					if(l <= r){
						if(l <= lt+v){
							al[++il]=b;
						}
						else{
							al[++il]=b-1;
						}
						al[il] += al[il-1];

						lt=l;
						l+=a;
					}
					else{
						if(r <= lt+v){
							ar[++ir]=d;
						}
						else{
							ar[++ir]=d-1;
						}
						ar[ir] += ar[ir-1];

						lt=r;
						r+=c;
					}
				}
				int xa = ca/(il+1);
				int xc = cc/(ir+1);
				int ans = xa*al[il] + xc*ar[ir];
				// for (int i=0; i<=il; i++){
				//     cout<<al[i]<<' ';
				// }cout<<endl;
				// for (int i=0; i<=ir; i++){
				//     cout<<ar[i]<<' ';
				// }cout<<endl;
				// cout<<"il = "<<il<<endl;
				// cout<<"ir = "<<ir<<endl;
				// cout<<"xa = "<<xa<<endl;
				// cout<<"xc = "<<xc<<endl;
				// cout<<"ca = "<<ca<<endl;
				// cout<<"cc = "<<cc<<endl;
				// cout<<"ans = "<<ans<<endl;
				// ans += al[ca%(il+1)]+ar[cc%(ir+1)];
				if(ca%(il+1) != 0)ans += al[ca%(il+1)-1];
				if(cc%(ir+1) != 0)ans += ar[cc%(ir+1)-1];

				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
