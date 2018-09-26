#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
ll ans=0;
ll solve(ll a,ll b)
{
	if(a<b)swap(a,b);
	if(b==0)
	{
		ans++;
		return a;
	}
	else
	{
		ans+=a/b;
		return solve(b,a%b);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	ll a,b;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b;
		ans=0;
		solve(a,b);
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}
