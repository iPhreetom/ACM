// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

typedef long long ll;

inline ll qk(ll a, ll b, ll p) {
	ll ans = 1 % p;
	for (a %= p; b; b >>= 1) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}

// 欧拉函数
const int MAXN = 2e6;
bool vis[MAXN];
int phi[MAXN], prime[MAXN];

void get_phi() {
    int tot = 0;
    phi[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++) {
            int d = i * prime[j];
            if (d >= MAXN) break;
            vis[d] = true;
            if (i % prime[j] == 0) {
                phi[d] = phi[i] * prime[j];
                break;
            }
            else phi[d] = phi[i] * (prime[j] - 1);
        }
    }
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;

	get_phi();
	while (T--) {
		int a, b, m;
		cin >> a >> b >> m;

		int mod = phi[m];
		int ans = 1;

		if (b==0) ans = 1;
		else if (b==1) ans = a%m;
		else if (b==2) ans = qk(a,a,m);
		else {
			int mi = a;
			for (int i=1; i<=b-2; i++) {
                if (mi < mod) mi = qk(a, mi, mod);
				else mi = qk(a, mi, mod) + mod;
			}
			ans = qk(a,mi,m);
		}
		cout << ans << endl;
	}
	return 0;
}
