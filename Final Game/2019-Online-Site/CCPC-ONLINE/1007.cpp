// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

char mp[4423][4423];

void dfs(int index, int n) {
	if(index > n) return;
	int len = (1<<index);
	int last = (1<<(index-1));

	// right
	int line = 1;
	int row = last+1;
	for (int i=line; i<=last;i++) {
		for (int j=row; j<=row+last; j++){
			mp[i][j] = mp[i][j-last];
		}
	}

	// down
	line = last+1;
	row = 1;
	for (int i=line; i<line+last;i++) {
		for (int j=row; j<row+last; j++){
			mp[i][j] = (mp[i-last][j]=='C'?'P':'C');
		}
	}

	// cover
	line = last+1;
	row = last+1;
	for (int i=line; i<line+last;i++) {
		for (int j=row; j<row+last; j++){
			mp[i][j] = mp[i-last][j-last];
		}
	}

	dfs(index+1,n);
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;

	mp[1][1] = 'C';
	mp[1][2] = 'C';
	mp[2][1] = 'P';
	mp[2][2] = 'C';
	dfs(2,10);

	while(T--){
		int n;
		cin >> n;
		int len = (1<<n);
		for (int i=1; i<=len; i++){
			for (int j=1; j<=len; j++){
				cout << mp[i][j] ;
			}
			cout << endl;
		}
	}
	return 0;
}
