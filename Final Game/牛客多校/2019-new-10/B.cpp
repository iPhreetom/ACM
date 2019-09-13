// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string s[501];
int f[201];

void dfs(int n,int k, int num) {
	// cout<<"n = "<<n<<endl;
	// cout<<"k = "<<k<<endl;
	// cout<<"num = "<<num<<endl;
	// cout << endl;
	if(num <= 0) return;
	if (n == 1 || n == 2) {
		int cnt = 0;
		for (int i=k-1; i<s[n].size(); i++) {
			cout << s[n][i];
			cnt++;
			if(cnt == num) break;
		}
		return ;
	}

	if (k > f[n-2]) {
		dfs(n-1,k-f[n-2],num);
	}
	else {
		int front = min(num, f[n-2]-k+1);
		dfs(n-2,k, front);
		if (front != num) {
			dfs(n-1,1LL, num-front);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	s[1] = "COFFEE";
	s[2] = "CHICKEN";
	f[1] = s[1].size();
	f[2] = s[2].size();

	for (int i=3; i<=63; i++) {
		f[i] = f[i-2]+f[i-1];
	}

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if(n>=63){
			if ((n-63)%2 == 1) n = 62;
			else n = 63;
		}

		int sz = min(f[n]-k+1,10LL);
		dfs(n,k,sz);
		cout << endl;
	}
	return 0;
}
