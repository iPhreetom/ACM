const int MAXN = 2e7;
int prime[MAXN+1];
int minPrime[MAXN+1];

void getPrime(){
    memset(prime, 0, sizeof(prime));
    for (int i=2; i<=MAXN; i++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            // minPrime[i] = i;
        }
        for(int j=1; j<=prime[0] && prime[j]*i<=MAXN; ++j){
            prime[prime[j]*i] = 1;
            // minPrime[prime[j]*i] = prime[j]; // 获得最小质因数
            if(i % prime[j] == 0) break;
        }
    }
}
