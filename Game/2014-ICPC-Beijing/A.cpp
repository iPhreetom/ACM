// fyt
#include<bits/stdc++.h>
// #define int long long
// #define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int>> a(11234);


signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	// cout<<fixed<<setprecision(2);
	int t;
	cin>>t;
	for (int j=1; j<=t; j++){
		int n;
		cin>>n;
		// a.clear();

		for (int i=0; i<n; i++){
		    int ti,xi;
			cin>>ti>>xi;
			a[i] = make_pair(ti,xi);
		}

		sort(a.begin(),a.begin()+n);

		double mx = 0;
		for (int i=1; i<n; i++){
			mx = max(mx,abs(a[i].second-a[i-1].second)*1.0/(a[i].first-a[i-1].first));
		}
		printf("Case #%d: %.2f\n",j,mx);
		// cout<<"Case #"<<j<<": ";
		// cout<<mx<<endl;
	}
	return 0;
}
