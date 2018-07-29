
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	for(int i=0;i<a.size()-2;i++){
		if(a[i]!='.' && a[i+1]!='.' && a[i+2]!='.'){
			if(a[i] != a[i+1] && a[i]!=a[i+2] && a[i+1]!=a[i+2]){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
