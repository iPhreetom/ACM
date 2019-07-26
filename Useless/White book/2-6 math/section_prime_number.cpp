#include<bits/stdc++.h>
using namespace std;

/*
区间筛法实现：
*/
typedef long long ll;
const int mxl = 1234560;


bool is_prime[mxl];
bool is_prime_small[mxl];

void segment_sieve(ll a,ll b){
	for(int i=0;i*i<b;i++)is_prime_small[i] = true;
	for(int i=0;i<b-a;i++)is_prime[i] = true;

	for(ll i=2;i*i<b;i++){
		if(is_prime_small[i]){
			for(ll j=i*2;j*j<b;j+=i)is_prime_small[i] = false;

			//(a+i-1)/i得到最接近a的i的倍数，最低是i的2倍，然后筛选
     		for(ll j=max(2LL,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;
			// 7 - 17 7+2-1 == 4 -- 8
			// 6 -- 6+2-1 /2 == 3 -- 6
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
