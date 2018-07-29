
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i=100000;i<900000;i++){
		bool ok = 1;
		for(int j=2;j<=sqrt(i);j++){
			if(i%j == 0){
				ok=0;
				break;
			}
		}
		if(ok){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
