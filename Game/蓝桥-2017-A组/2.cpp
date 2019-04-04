#include<bits/stdc++.h>
// #define int long long
// #define double long double
#define print(x) cout << #x << ": "<< x << endl;
#define endl '\n'
using namespace std;

bool vis[987654322];
int index[9];
signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	vis[123456789] = 1;
	queue<pair<int,int> > que;
	que.push(make_pair(123456789, 0));
	while (!que.empty()) {
		int num = que.front().first;
		int d = que.front().second;
		que.pop();
		if (num == 876543219) {
			cout << d <<endl;
		}

		int tp = num;
		int cnt = 0;
		int place = 0;
		while (tp>0) {
			index[cnt] = tp%10;
			tp/=10;
			if(index[cnt] == 9)place = cnt;
			cnt++;
		}
		// 1
		int place1 = (place+1)%9;
		int val1 = num - index[place]*pow(10,place) - index[place1]*pow(10,place1) +
		 	index[place]*pow(10,place1) + index[place1]*pow(10,place);
		if (vis[val1] == 0) {
			vis[val1] = 1;
			que.push(make_pair(val1,d+1));
		}

		// 2
		place1 = (place+2)%9;
		val1 = num - index[place]*pow(10,place) - index[place1]*pow(10,place1) +
		 	index[place]*pow(10,place1) + index[place1]*pow(10,place);
		if (vis[val1] == 0) {
			vis[val1] = 1;
			que.push(make_pair(val1,d+1));
		}

		// 3
		place1 = (place-1+9)%9;
		val1 = num - index[place]*pow(10,place) - index[place1]*pow(10,place1) +
		 	index[place]*pow(10,place1) + index[place1]*pow(10,place);
		if (vis[val1] == 0) {
			vis[val1] = 1;
			que.push(make_pair(val1,d+1));
		}

		// 4
		place1 = (place-2+9)%9;
		val1 = num - index[place]*pow(10,place) - index[place1]*pow(10,place1) +
		 	index[place]*pow(10,place1) + index[place1]*pow(10,place);
		if (vis[val1] == 0) {
			vis[val1] = 1;
			que.push(make_pair(val1,d+1));
		}
	}
	return 0;
}
