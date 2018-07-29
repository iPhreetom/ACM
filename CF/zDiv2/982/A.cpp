
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string a;
	cin>>a;

	char last,now;
	if(a.size()==1){
		if(a[0]=='1')cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		return 0;
	}

	if(a.size()==2){
		if(a[0] == '1'){
			if(a[1] == '1'){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		else{
			if(a[1]=='0'){
				cout<<"No"<<endl;
			}
			else{
				cout<<"Yes"<<endl;
			}
		}
		return 0;
	}

	if((a[0] == '0' && a[1] == '0') || (a[a.size()-1]=='0'&& a[a.size()-2]=='0')){
		cout<<"No"<<endl;
		return 0;
	}

	int c1=0,c0=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='1'){
			c0=0;
			c1++;
		}
		else{
			c1=0;
			c0++;
		}

		if(c1 == 2){
			cout<<"No"<<endl;
			return 0;
		}
		if(c0 == 3){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;

	return 0;
}
