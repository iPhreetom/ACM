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
		int up=0,down=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(i)
			{
				up+=(a[i]>a[i-1]);
				down+=(a[i]<a[i-1]);
			}
		}
		if(up<=1||down<=1)
		{
			bool f1=0,f2=0;int f=0,t=0;
			if(up<=1)
			{
				for(int i=1;i<n;i++)
				{
					if(a[i]>a[i-1])
					{
						if(!f)
						{
							f=i;
							t=a[i];
							a[i]=a[i-1];
						}
						else
						{
							f1=1;break;
						}
					}
				}
				if(f)a[f]=t;
			}
			f=0;
			if(down<=1)
			{
				for(int i=1;i<n;i++)
				{
					if(a[i]<a[i-1])
					{
						if(!f)
						{
							f=i;
							t=a[i];
							a[i]=a[i-1];
						}
						else
						{
							f2=1;break;
						}
					}
				}
			}
			if(f1&&f2)cout<<"NO\n";
			else cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}
