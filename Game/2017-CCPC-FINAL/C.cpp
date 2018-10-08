#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

	int a[10] = {1,9,41,109,205,325,473,649,853,1085}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,t;

	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		int sum = 0;
		int x,y,k;
		cin>>x>>y>>k;
		swap(x,y);
		if(x == y){
			int now = 0;
			for (int i=0; i<k; i++){
				if(x*11 - y*9 <= now){
					now -= x*11 - y*9;
					sum++;
				}
				else{
					now += 11*y;
				}
			}
		}
		else if(x < y){
			sum = k;
		}
		else if(x > y){
			int now = 0;
			for (int i=0; i<k; i++){
				if(x*11 - y*9 <= now){
					now -= x*11 - y*9;
					sum++;
				}
				else{
					now += 11*y;
				}
			}
		}
		cout<<"Case #"<<ii<<": "<<sum<<"\n";
	}
	return 0;
}
