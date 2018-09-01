#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[12];
int num[1123456];
inline int lcm(int a,int b)
{
	return a*b/__gcd(a,b);
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,len;
	while(cin>>n>>len){
		n--;
		for (int i=0; i<len; i++){
		    cin>>a[i];
			if(a[i]==0)
			{
				if(i==0)continue;
				else a[i]=a[i-1];
			}
			else if(i==1&&a[0]==0)a[0]=a[1];
		}
		n--;
		int cur=1,cnt=0,ans=0;
		for (int i=1; i<(1<<len); i++){
			cnt=0;cur=1;
			for (int j=0; j<len; j++){
				if((i>>j)&1)
				{
					cnt++;
					cur=lcm(cur,a[j]);
				}
			}
			//cout<<cur<<" "<<i<<" "<<ans<<endl;
			ans+=(n/cur)*(cnt%2?1:-1);
		}
		cout<<ans<<endl;
	}

	return 0;
}
