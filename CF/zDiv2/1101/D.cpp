#include<bits/stdc++.h>
// #define int long long
#define double long double
using namespace std;

int n;
vector<int> mp[212345];
vector<int> a(212345,0);

const int MAXN = 2e5;
int prime[MAXN+1];

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

int solve(int p) {
	for (int i=1; i<=n; i++){
		// if(a[i])
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getPrime();
	cout<<"prime[0] = "<<prime[0]<<endl;
	cin >> n;
	for (int i=1; i<=n; i++){
	    cin >> a[i];
	}
	for (int i=1; i<=n-1; i++){
	    int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	int ans = 0;
	for (int i=1; i<=prime[0]; i++){
		ans = max(ans, solve(prime[i]));
	}
	cout << ans << endl;
	return 0;
}
