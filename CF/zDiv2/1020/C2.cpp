// CF 1020C Elections（贪心）
// 	一句话描述：
// 		贪心
// 	知识点：
// 		贪心的方法：最好不要选择一步步模拟贪心
// 			一般来说，这样是写不出来的，同样也是不正确的
// 		而暴力贪心的方法是,枚举某一种答案状态

#include <bits/stdc++.h>
using namespace std;
#define mem(x) memset(x,0,sizeof(x))
#define mem1(x) memset(x,-1,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define endl "\n"
typedef long long ll;
inline int rint() { int a; scanf("%d", &a); return a; }
inline long long rll() { long long a; scanf("%lld", &a); return a; }
inline double rdouble() { double a; scanf("%lf", &a); return a; }
ll gcd(ll a, ll b) { return (b) ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
ll pow(ll a, ll b, ll q) { ll k = a; ll ans = 1; while (b) { if (b & 1) ans = ans * k%q; k = k * k%q; b >>= 1; }return ans; }
ll countOnes(ll x) { ll c = 0; for (; x; x >>= 1) c += x & 1; return c; }
const double eps = 1e-9;
const ll mod = 1e9 + 7;
const ll inf = 1e9 + 7;
const int N = 3005;
vector <ll> v[N];
int main() {
	int n = rint(), m = rint();
	for (int i = 1; i <= n; i++) {
		int p = rint();
		ll c = rll();
		v[p].push_back(c);
	}

	for (int i = 1; i <= m; i++)
		sort(all(v[i]), greater<ll>());

	int maxx = 0;
	int q = 0;
	for (int i = 2; i <= m; i++)
		q++,maxx = max(maxx, (int)v[i].size());

	if (maxx < v[1].size()) return puts("0");
	ll ans = 0;
	ll minn = 1e17 + 7;
	for (int i = maxx + 1; i >= 1; i--) {
		priority_queue <ll, vector<ll>, greater<ll>> pq;
		for (int j = 2; j <= m; j++) {
			if (v[j].size() >= i) {
				ans += v[j][v[j].size() - 1];
				v[j].pop_back();
				v[1].push_back(1);
			}
			for (int k = 0; k < v[j].size(); k++) pq.push(v[j][k]);
		}
		ll aa = ans;
		ll tt = v[1].size();
		while (!pq.empty() && tt < i) {
			tt++;
			aa += pq.top();
			pq.pop();
		}
		if(i <= tt){
			minn = min(minn, aa);
		}
	}
	cout << minn << endl;
	return 0;
}
