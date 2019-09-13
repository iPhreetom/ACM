// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string ans[] = {"Lbnb!","Zgxnb!","Tankernb!"};
typedef long long ll;

// O(1)
ll mul(ll a, ll b, ll p) {
    return (ll)(__int128(a) * b % p);
}

// ax + by = gcd(a, b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 前置：exgcd
ll excrt(vector<ll>& m, vector<ll>& r) {
    ll M = m[0], R = r[0], x, y, d;
    for (int i = 1; i < m.size(); i++) {
        d = exgcd(M, m[i], x, y);
        if ((r[i] - R) % d) return -1;
        x = mul(x, (r[i] - R) / d, m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
		if(R > 1e18)return -1;
    }
    return R >= 0 ? R : R + M;
}

int f[112345];
set<int> s;
void getf() {
	f[0] = 1;
	f[1] = 1;
	s.insert(1);
	s.insert(0);
	for (int i=2; i<=112344; i++) {
		f[i] = f[i-1]+f[i-2];
		s.insert(f[i]);
		if(f[i] > 1e18) break;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	getf();
	vector<int> v;
	vector<int> mod;
	for (int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(a);
		mod.push_back(b);
	}
	
	int num = excrt(mod,v);
	if (num == -1) {
		cout << ans[2] << endl;
	}
	else {
		if (s.count(num) == 0) {
			cout << ans[1] << endl;
		}
		else cout << ans[0] << endl;
	}
	return 0;
}
