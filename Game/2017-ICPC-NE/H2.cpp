#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

long long socre(long long a,long long b,long long c)
{
	if(a<b) swap(a,b);	if(a<c) swap(a,c);	if(b<c) swap(b,c);
	return a*a+b*b+c*c+c*7;
}
int main()
{
	long long n,a,b,c,d,ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long t1,t2,t3,tmax=0;
		cin>>a>>b>>c>>d;
		if(a<b) swap(a,b);	if(a<c) swap(a,c);	if(b<c) swap(b,c);
		if(a>=c+4||(d>=4))
		{
			a+=d;
			ans=a*a+b*b+c*c+c*7;
			cout<<ans<<endl;
		}
		else
		{
			for(long long i1=a;i1<=a+d;i1++)
			for(long long i2=b;i2<=b+d;i2++)
			for(long long i3=c;i3<=c+d;i3++)
			{
				if(i1+i2+i3==(a+b+c+d))
				{
					if(socre(i1,i2,i3)>tmax) tmax=socre(i1,i2,i3),t1=i1,t2=i2,t3=i3;
				}
			}
			ans=socre(t1,t2,t3);
			cout<<ans<<endl;
		}


	}
	return 0;
}
