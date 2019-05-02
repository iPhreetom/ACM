#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int cnt[20];

void f(int l,int r) {
	for (int i=l; i<=r; i++) {
		cnt[i]++;
	}
}

void g(int l, int r) {
	for (int i=l; i<=r; i++) {
		for (int j=i; j<=r; j++) {
			f(i,j);
		}
	}
}

void w(int l, int r) {
	for (int i=l; i<=r; i++) {
		for (int j=i; j<=r; j++) {
			g(i,j);
		}
	}
}


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int mx = 25;
	for (int n=1; n<=mx; n++) {
		memset(cnt,0,sizeof(cnt));
		w(1,n);
		for (int i=1; i<=(mx-n); i++) {
			cout <<  ' ';
		}
		for (int i=1; i<=n; i++) {
		    cout << cnt[i]%2 << ' ';
		}
		cout << endl;
	}
	return 0;
}
