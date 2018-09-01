#include <cstdio>
#include <algorithm>
using namespace std;
long long a[20], b[20];
int m[20];
long long dp[1<<20];
inline int cnt(int x) {
	int cc = 1; while (x) { cc++; x >>= 1; }; return cc;
}
int main(int argc, char const *argv[]) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int s; scanf("%lld %lld %d", &a[i], &b[i], &s);
		for (int j = 0; j < s; ++j) {
			int p; scanf("%d", &p); p--;
			m[i] |= 1<<p;
		}
	}
	long long mmax = 0;
	for (int i = 1; i < 1<<n; ++i) {
		for (int j = 0; j < n; ++j) {
			int t = 1<<j;
			if ((i&t) && ((((i^t)^m[j])&m[j]) == 0)) {
				dp[i] = max(dp[i], dp[i^t] + cnt(i^t) * a[j] + b[j]);
				mmax = max(mmax, dp[i]);
			}
		}
	}
	printf("%lld\n", mmax);
	return 0;
}
