// fyt
#include<bits/stdc++.h>
using namespace std;

// Hash
using ull = unsigned long long;
const int maxn = 1e5+7;
const int base = 135, mod1 = 1e9+7, mod2 =  1e9+9;
ull mul1[maxn],mul2[maxn],unite[maxn];

void init_mul() {
	mul1[0] = mul2[0] = 1;
	for (int i=1; i<maxn; i++){
		mul1[i] = mul1[i-1]*base%mod1;
		mul2[i] = mul2[i-1]*base%mod2;
	}
}

vector<int> init_hash(const string& s) {
	ull res1 = 0, res2 = 0;
	int n = s.size();
	// vector<int> v; // h
	unite[n+1] = 0;
	for (int i=n; i>=0; i--) {
		res1 = (res1*base + s[i])%mod1;
		res2 = (res2*base + s[i])%mod2;
		unite[i] = (res1 << 32) | res2;
	}
}

ull get_hash(int l, int r) {
	r++;
	int len = r-l;
	unsigned int mask32 = (~0u);
	ull l1 = unite[l]>>32, r1 = unite[r]>>32; // high32
	ull l2 = unite[l]&mask32, r2 = unite[r]&mask32;
	ull res1 = (l1 - r1*mul1[len]%mod1 + mod1)%mod1;
	ull res2 = (l2 - r2*mul2[len]%mod2 + mod2)%mod2;
	return (res1 << 32)|res2;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int mask32 = (~0U);
	ull mask64 = (~0ULL);
	ull masklow = (~0U);
	ull maskhigh = (masklow << 32);
	cout << bitset<66>(maskhigh) << endl;

	return 0;
}
