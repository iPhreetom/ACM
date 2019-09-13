// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int v[2123];
int n,k,x;

int tryit(int index) {
	int lt = index;
	int rt = index+1;
	int cnt = 1;
	int now = x;
	int sum = 0;
	while(lt >= 0 || rt < n) {
		if (lt >= 0) now = v[lt];
		else now = v[rt];

		while (lt >= 0 && v[lt] == now) cnt++,lt--;
		while (rt < n && v[rt] == now) cnt++,rt++;
		if (cnt >= 3) {
			sum += cnt;
			cnt = 0;
			continue;
		}
		else break;
	}
	return sum-1;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k >> x;

	for (int i=0; i<n; i++){
		cin>>v[i];
	}
	int mx = 0;
	for (int i=0; i<n; i++){
		if (v[i] == x)mx = max(mx,tryit(i));
	}
	cout << mx << endl;
	return 0;
}
