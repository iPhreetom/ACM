#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;
typedef long long ll;

int a[MAXN+1];
const int MAXN = 2e7;
int prime[MAXN+1];
int minPrime[MAXN+1];

void getPrime(){
    memset(prime, 0, sizeof(prime));
    for (int i=2; i<=MAXN; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            minPrime[i] = i;
        }
        for(int j=1; j<=prime[0] && prime[j]*i<=MAXN; ++j){
            prime[prime[j]*i] = 1;
            minPrime[prime[j]*i] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getPrime();

	a[1]=1;
	for (int i=2; i<=MAXN; i++){
	   	// long long mm = minPrime[i];
		// if(mm*mm < MAXN && mm*mm*mm < MAXN && i%(mm*mm*mm) == 0)a[i]=0;
		// else if(mm*mm < MAXN && i%(mm*mm)==0)a[i]=a[i/mm/mm];
		// else a[i] = 2*a[i/mm];
		int mm = minPrime[i];
        if((ll)mm*mm<MAXN && (ll)mm*mm*mm<MAXN && i%(mm*mm*mm)==0)a[i] = 0;
        else if((ll)mm*mm<MAXN && i%(mm*mm)==0) a[i] = a[i/mm/mm]; // i/mm/mm这个数 没有mm这个因子 因为mm是i的最小因子
        else a[i] = 2 * a[i/mm];
	}
	for (int i=1; i<=MAXN; i++){
	    a[i] += a[i-1];
	}

	int t;
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
