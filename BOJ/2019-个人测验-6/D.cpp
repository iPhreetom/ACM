// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(y1 > y2) {
		swap(x1,x2);
		swap(y1,y2);
	}
	int n;
	cin >> n;
	int ans = 0;
	vector<pair<double,pair<double,double> > > v;
	for (int i=1; i<=n; i++){
		double a,b,c;
		cin >> a >> b >>c;
		if (y1)
		double yt1 = (-c + (-a*x1));
		double yt2 = (-c + (-a*x2));
		if (y1 <= yt1 && yt1 <= y2 && y1 <= yt2 && yt2 <= y2) {
			ans++;
		}
		// v.push_back(make_pair(a,make_pair(b,c)));
	}
	cout << ans << endl;
	return 0;
}
