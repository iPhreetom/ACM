#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[10] = {1,9,41,109,205,325,473,649,853,1085};
// 232

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		int n;
		int sum = 0;
		cin>>n;
		if(n <= 9){
			sum = a[n];
		}
		else{
			int dif = n-9;
			sum = a[9] + 232*dif + (dif + 1)*dif/2*28;
		}
		cout<<"Case #"<<ii<<": "<<sum<<"\n";
	}
	return 0;
}
