// fyt
#include<bits/stdc++.h>
using namespace std;

int mp[200][200];
int cnt = 0;
int c[10];
int n;

void dfs(int index, int color) {
	if(index == n) {
		cnt++;
		return ;
	}
	for (int i=1; i<=4; i++){
		bool ok = 1;
	    for (int j=1; j<=index; j++){
			if(mp[index+1][j] && c[j] == i)ok = 0;
	    }
		if(ok) {
			c[index+1] = i;
			dfs(index+1,i);
			c[index+1] = 0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> mp[i][j];
		}
	}
	for (int i=1; i<=4; i++){
		c[1] = i;
	    dfs(1,i);
	}
	cout << cnt << endl;
	return 0;
}
