#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  string s, t;
  cin >> n >> m;
  cin >> s >> t;
  if (n > m + 1) {
    cout << "NO\n";
    return 0;
  }
  int p1, p2;
  for (p1 = 0; p1 < n; p1++) {
    if (s[p1] != t[p1])
      break;
  }
  p1--;
  for (p2 = n; p2 > p1; p2--) {
    if (s[p2] != t[m - n + p2])
      break;
  }
  if (p2 == p1) {
    if (m == n) {
      cout << "YES\n";
      return 0;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  if (p2 - p1 > 1) {
    cout << "NO\n";
    return 0;
  }
  if (s[p1 + 1] != '*') {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}
