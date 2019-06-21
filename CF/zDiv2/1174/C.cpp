// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int num[512345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int index = 0;
	for (int i=2; i<=1e5; i++){
		if (num[i] != 0) continue;
		index++;
		for (int j=i; j<=1e5;j+=i) {
			num[j] = index;
		}
	}
	for (int i=2; i<=n; i++){
		cout << num[i] << ' ';
	}
	cout << endl;
	return 0;
}
