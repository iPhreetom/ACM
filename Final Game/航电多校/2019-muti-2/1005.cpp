#include<bits/stdc++.h>
#define int long long
using namespace std;

const long long MOD = 998244353;

long long powMod(long long a, long long b)
{
	long long ans = 1;
	for (a %= MOD; b; b >>= 1)
	{
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
	}
	return ans;
}

long long inv(long long x) { return powMod(x, MOD - 2); }

const int maxn = 3337;
const int MAXN = 3337;
long long avgup[maxn];
long long ans[maxn];
long long four;
long long two;
// 组合数打表
long long C[MAXN][MAXN];

void initC() {
    C[0][0] = 1;
    for (int i = 1; i < MAXN - 5; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

void getans() {
	ans[2] = 2*inv(3)%MOD;
	for (int i=3; i<maxn; i++){
		int sum = 0;
		sum += avgup[i]*four%MOD;

		int fenzi = 0;
		for (int j=2; j<i; j++) { // c de fenzi
			// if (i == 3) cout<<"ans[j] = "<<ans[j]<<endl;
			// if (i == 3) cout<<"C[i][j] = "<<C[i][j]<<endl;
			fenzi += C[i][j]*ans[j]%MOD;
			fenzi %= MOD;
		}

		// get 第一项
		sum = (sum + fenzi)%MOD;
		sum = sum * inv(powMod(2, i))%MOD;

		// 等比数列
		sum = (sum*powMod(2, i))%MOD;
		long long fenmu = (powMod(2, i)-1+MOD)%MOD;
		sum = (sum*inv(fenmu))%MOD;


		ans[i] = (sum+avgup[i]*four%MOD)%MOD;
	}
	// cout<<"ans[3] = "<<ans[3]<<endl;
}

void init() {
	for (int i=1; i<maxn; i++){
		avgup[i] = (i*(i-1));
	}

	getans();
}


signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	four = inv(4);
	initC();
	init();

	while (cin >> n) {
		long long sum = 0;
		for (int i=2; i<=n; i++) {
			sum = (sum + (ans[i]*inv(n))%MOD)%MOD;
		}
		cout << sum <<endl;
	}
	return 0;
}
