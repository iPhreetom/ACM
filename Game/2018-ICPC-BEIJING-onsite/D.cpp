#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll f[212];
	f[1] = 1;
	f[2] = 2;
	int len = 3;
	for(int i=3;;i++){
		f[i] = f[i-1] + f[i-2];
		if(f[i] > 1e10){
			len = i;
			break;
		}
	}


	ll m;
	while(cin>>m){
		//cout<<endl<<endl;
		if(m == 0){
			cout<<"1 1"<<endl;
			cout<<"2 1"<<endl;
			continue;
		}

		int l = 0;
		while(m > 1){
			for(int i=1;i<=len;i++){
				if(f[i] > m){
					m -= (f[i-1]-1);
					cout<<l+i-1<<' '<<l+i+1<<endl;
					cout<<l+i<<' '<<l+i<<endl;
					l += i+1;
					break;
				}
			}
		}
		cout<<l<<' '<<199<<endl;
		cout<<l+1<<' '<<l+1<<endl;
	}
}
