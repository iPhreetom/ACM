#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int maxn=30000+5;
const double gol=0.6180339887498949;
double a[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	double cur1,cur2,ans1=1,ans2=1e5+5;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		int l=i+1,r=n;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(a[mid]*gol>a[i])r=mid;
			else l=mid;
		}
		cur1=a[i];
		for(int j=l-1;j<=l+1;j++)
		{
			cur2=a[j];
			if(abs(cur1/cur2-gol)<abs(ans1/ans2-gol))
			{
				ans1=cur1,ans2=cur2;
			}
		}
	}
	cout<<(int)ans1<<endl<<(int)ans2<<endl;
	return 0;
}
