#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int maxn=2e5+5;
double x[maxn],y[maxn],s[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>s[i];
	double l=0,r=1e7+5;
	for(int t=0;t<750;t++)
	{
		double mid=(l+r)/2,cur=0;bool f=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]/mid>y[i]-cur)
			{
				f=1;break;
			}
			else if(s[i]/mid<x[i]-cur)
			{
				cur=x[i];
			}
			else
			{
				cur+=s[i]/mid;
			}
		}
		if(f)l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(2)<<l<<endl;
	return 0;
}
