#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[] ={4,10,20,35,56,83,116,155,198,244,292,341,390,439,488,537,586,635,684,733};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;

	if(n <= 20){
		cout<<a[n-1]<<endl;
	}
	else{
		cout<<a[19]+(n-20)*49<<endl;
	}
	return 0;
}
