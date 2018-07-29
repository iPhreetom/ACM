#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k;
	cin>>n>>k;
	while(k--){
		int t = n%10;
		if(t == 0){
			n /= 10;
		}
		else{
			n--;
		}
	}
	cout<<n<<endl;

	return 0;
}
