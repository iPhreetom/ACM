#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		if(n != 4){
			for (int i=0; i<n; i++){
			    int t;
				cin>>t>>t;
			}
			cout<<"NO"<<endl;
		}
		else{
			vector<pair<int,int> > a;
			for (int i=0; i<4; i++){
			    int x,y;
				cin>>x>>y;
				a.push_back(make_pair(x,y));
			}
			sort(a.begin(),a.end());
			bool ok = 0;
			if(a[0].first == a[1].first && a[2].first == a[3].first){
				if(a[0].second == a[2].second && a[1].second == a[3].second){
					if(a[1].second - a[0].second == a[2].first - a[0].first){
						ok = 1;
					}
				}
			}
			if(a[1].first == a[2].first && a[0].second == a[3].second){
				if(a[2].second - a[1].second == a[3].first - a[0].first){
					int x2 = a[2].first;
					int x0 = a[0].first;
					int y2 = a[2].second;
					int y0 = a[0].second;
					int y1 = a[1].second;
					if(x2 - x0 == y2 - y0 && y2 - y0 == y0 - y1){
						ok = 1;
					}
				}
			}
			if(ok)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
