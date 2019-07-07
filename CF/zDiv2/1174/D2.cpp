// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int pre[512345];
int ans[512345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,x;
	cin >> n >> x;
	int index = 1;
	int len = 1;
	int mx = pow(2,n);
	set<int> s;
	while(index < x) {
		if (index >= mx) break;
		ans[len] = index++;
		pre[len] = pre[len-1]^ans[len];
		// 和前面抑或得0
		// 和前面抑或得x
		// 其他都可以
		while (s.count(pre[len])!=0 || s.count(pre[len]^x)!=0 || pre[len]==x || pre[len]==0) {
			if (index >= mx) break;
			ans[len] = index++;
			pre[len] = pre[len-1]^ans[len];
		}
		if (index >= mx) break;
		s.insert(pre[len]);
		len++;
	}
	cout << len-1 << endl;
	for (int i=1; i<=len-1; i++){
		cout << ans[i] << ' ';
	}cout << endl;
	return 0;
}
