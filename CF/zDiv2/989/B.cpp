
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n,p;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>p;

	string a;
	cin>>a;

	bool ok = 0;
	for(int i=0;i<n-p;i++){
		if(a[i]=='.' || a[i+p]=='.'){
			if(a[i]=='.' && a[i+p]=='.'){
				a[i]='1';
				a[i+p]='0';
				ok = 1;
				break;
			}
			else{
				if(a[i]=='.'){
					ok=1;
					if(a[i+p]=='1')a[i]='0';
					else a[i]='1';
				}
				else{
					ok=1;
					if(a[i]=='1')a[i+p]='0';
					else a[i+p]='1';
				}
			}
		}
		else{
			if(a[i]!=a[i+p])ok=1;
		}
	}
	if(ok){
		for(int i=0;i<n;i++){
			if(a[i]=='.')a[i]='0';
		}
		cout<<a<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
