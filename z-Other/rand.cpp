#include <bits/stdc++.h>
#define int long long
using namespace std;
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))

stringstream ss;

signed main(int argc, char *argv[]) {
  int seed = time(NULL);
  if (argc > 1) //如果有参数
  {
    ss.clear();
    ss << argv[1];
    ss >> seed; //把参数转换成整数赋值给seed
  }
  srand(seed);
  bool h = 0;
  int n = random(2, 4);
  cout << n << endl;
  int m = random(2, 6);
  cout << m << endl;
  for (int i = 0; i < n; i++) {
    if (!h) {
      if (random(0, 9) == 0) {
        cout << '*';
        h = 1;
      } else if (random(0, 9) % 2) {
        cout << 'a';
      } else
        cout << 'b';
    } else {
      if (random(0, 1)) {
        cout << 'a';
      } else
        cout << 'b';
    }
  }
  cout << endl;

  h = 1;
  for (int i = 0; i < m; i++) {
    if (!h) {
      if (random(0, 9) == 0) {
        cout << '*';
        h = 1;
      } else if (random(0, 9) % 2) {
        cout << 'a';
      } else
        cout << 'b';
    } else {
      if (random(0, 1)) {
        cout << 'a';
      } else
        cout << 'b';
    }
  }
  cout << endl;
  return 0;
}
