#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    if (s.compare(t) != 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (m < n - 1) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < idx; i++) {
    if (s[i] != t[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  int i = n - 1, j = m - 1;
  while (i > idx) {
    // cout << "idx = " << idx << endl;
    if (s[i] != t[j]) {
      cout << "NO" << endl;
      return 0;
    }
    i--, j--;
  }

  cout << "YES" << endl;
  return 0;
}
