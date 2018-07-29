
#include<bits/stdc++.h>
using namespace std;

long long res,child,tp;
string a;
long long n,x;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>x;

	for(int i=0;i<n;i++){
		cin>>a;
		cin>>tp;
		if(a == "-"){
			if(x >= tp){
				x-=tp;
			}
			else{
				child++;
			}
		}
		else{
			x+=tp;
		}
	}
	cout<<x<<' '<<child<<endl;
	return 0;
}
