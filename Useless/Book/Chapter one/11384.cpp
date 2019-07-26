// 10
// 简单递归，找最少操作数
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int digui(int index) {
	if(index <= 2) {
		return index;
	}
	else {
		return 1 + digui(index/2);
	}
}
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	while (cin >> n) {
		cout << digui(n) << endl;
	}
	return 0;
}
