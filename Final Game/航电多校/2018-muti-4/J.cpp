// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string mp[17];
int ans = 0;
bool findit = 0;
int eve[17];
int mn = 1e18;

inline int get(char& ch) {
	if ('0'<=ch && ch <='9') return ch-'0';
	return ch-'A'+10;
}

bool check(int index) {
	// x轴
	int x = index%4;
	int y = index/4;
	// 横向
	bool vis[16];
	for (int i=y*4; i<4*y+4; i++){
		memset(vis,0,sizeof(vis));
		for (int j=0; j<x*4+4; j++){
			if (vis[get(mp[i][j])]) return false;
			vis[get(mp[i][j])] = 1;
		}
	}

	for (int j=x*4; j<x*4+4; j++){
		memset(vis,0,sizeof(vis));
		for (int i=0; i<4*y+4; i++){
			if (vis[get(mp[i][j])]) return false;
			vis[get(mp[i][j])] = 1;
		}
	}
	return true;
}

void rotate(int index) {
	char temp[4][4];

	int x = index%4;
	int y = index/4;
	int cnt = 0;
	for (int i=y*4; i<4*y+4; i++){
		int cnt2 = 0;
		for (int j=x*4; j<x*4+4; j++){
			temp[cnt][cnt2++] = mp[i][j];
		}
		cnt++;
	}
	// ABC  GDA  JHG
	// DEF  HEB
	// GHJ  JFC

	cnt = 0;
	for (int i=y*4; i<4*y+4; i++){
		int cnt2 = 3;
		for (int j=x*4; j<4+x*4; j++){
			mp[i][j] = temp[cnt2--][cnt];
		}
		cnt++;
	}
}

void dfs(int index){
	if (check(index)) {
		if (index == 15) {
			// findit = true;
			mn = min(mn,ans);
			return;
		}
		for (int i=1; i<=4 && !findit; i++){
			dfs(index+1);
			if (!findit) eve[index+1]++,ans++,rotate(index+1);
		}
		if (!findit) ans -= 4, eve[index+1]-=4;
	}
}

void solve() {
	for (int i=1; i<=4 && !findit; i++){
		dfs(0);
		if (!findit) ans++,eve[0]++,rotate(0);
	}
	int sum1 = 0;
	int sum2 = 0;
	for (int i=0; i<16; i++){
		sum1 += eve[i];
		// sum2 += (4+eve[i])%4;
	}
	// cout << min(sum1,sum2) << endl;
	cout << mn << endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<16; j++){
			cin >> mp[j];
		}
		ans = 0;
		findit = 0;
		memset(eve,0,sizeof(eve));
		mn = 1e18;
		solve();
		// for (int j=0; j<16; j++){
		//     cout << mp[j] << endl;
		// }
	}
	return 0;
}
