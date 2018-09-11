#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
const int maxn=1e5+5;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];

		bool f1=0,f2=0;
		int t=0,ti=-1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				if(ti!=-1)
				{
					f1=1;break;
				}
				else
				{
					if((i==1||a[i]<a[i-2]))
					{
						ti=i-1;
						t=a[i-1];
					}
					else
					{
						ti=i;
						t=a[i];
						a[i]=a[i-1];
					}
				}
			}
		}
		if(ti!=-1)
		{
			ti=-1;a[ti]=t;
		}

		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				if(ti!=-1)
				{
					f2=1;break;
				}
				else
				{
					if((i==1||a[i]>a[i-2]))
					{
						ti=i-1;
						t=a[i-1];
					}
					else
					{
						ti=i;
						t=a[i];
						a[i]=a[i-1];
					}
				}
			}
		}
		if(f1&&f2)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
