// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int MAXN = 3e3+15;
int a[MAXN][MAXN];
int b[MAXN*MAXN];
int c[MAXN];

int mp[MAXN][MAXN];

// 下标从0开始
int st[MAXN][13]; // 22 = ((int)log2(MAXN) + 1)

int xlog(int x) { return 31 - __builtin_clz(x); }

void init(int *a, int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int x = xlog(r - l + 1);
    return min(st[l][x], st[r - (1 << x) + 1][x]);
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,w,h;
	cin >> n >> m >> w >> h;
	int g0,x,y,z;
	cin >> g0 >> x >> y >> z;

	b[0] = g0;
	for (int i=1; i<n*m; i++){
		b[i] = (b[i-1]*x+y)%z;
	}

	int cnt = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			a[i][j] = b[cnt];
			cnt++;
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			c[j] = a[i][j];
		}
		init(c,m);
		for (int j=0; j<m-h+1; j++){
			mp[i][j] = query(j,j+h-1);
		}
	}

	for (int j=0; j<m-h+1; j++){
		for (int i=0; i<n; i++){
			c[i] = mp[i][j];
		}
		init(c,n);
		for (int i=0; i<n-w+1; i++){
			mp[i][j] = query(i,i+w-1);
		}
	}

	int sum = 0;
	for (int i=0; i<n-w+1; i++){
		for (int j=0; j<m-h+1; j++){
			sum += mp[i][j];
		}
	}

	cout << sum << endl;
	return 0;
}
