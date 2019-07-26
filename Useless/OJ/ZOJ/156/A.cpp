// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int times ;
	int four[5] = {0,1,2,2,4};
	cin >> times ;
	while( times-- ) {
		int x;
		cin >> x;
		// x = 24 - times;

		if(x <= 4) {
			cout<<four[x]<<endl;
			continue;
		}
		x -= 4;

		int base = 4;
		int sum = 0;
		while(sum+base < x) {
			sum += base;
			base *= 2;
		}
		x -= sum;

		int cnt = 0;
		while(x != 1) {
			for (int i=62; i>=0; i--){
				if( (1ll<<i) < x) {
					x -= (1ll<<i);
					cnt++;
					break;
				}
			}
		}

		cout<<(1ll<<(cnt+1))<<endl;
	}
	return 0;
}
