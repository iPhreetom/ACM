#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
// #ifdef zerol #define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
// void err() { cout << "\033[39;0m" << endl; }
// template<template<typename...> class T, typename t, typename... A>
// void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
// template<typename T, typename... A>
// void err(T a, A... x) { cout << a << ' '; err(x...); }
// #else
// #define dbg(...)
// #endif
// ----------------------------------------------------------------------------

LL ex_gcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) { x = 1; y = 0; return a; }
	LL ret = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return ret;
}
LL CRT(LL *m, LL *r, LL n)
{
	if (!n) return 0;
	LL M = m[0], R = r[0], x, y, d;
	FOR (i, 1, n)
	{
		d = ex_gcd(M, m[i], x, y);
		if ((r[i] - R) % d) return -1;
		x = (r[i] - R) / d * x % (m[i] / d);
		R += x * M;
		M = M / d * m[i];
		R %= M;
	}
	return R >= 0 ? R : R + M;
}

LL mod[] = {3, 5, 7, 8, 11, 13, 17};
LL rem[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t, n, m;
	cin >> t >> n >> m;
	for(int kase = 1; kase <= t; kase++)
	{
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 18; j++)
			{
				cout << mod[i] << ' ';
			}
			cout << endl;

			int x, r = 0;
			for(int j = 0; j < 18; j++)
			{
				cin >> x;
				r += x;
			}
			rem[i] = r % mod[i];
			// cout << rem[i] << endl;
		}
		LL ans = CRT(mod, rem, 7);
		cout << ans << endl;
		cin >> ans;
	}
	return 0;
}
