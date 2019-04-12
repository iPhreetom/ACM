// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,h;
	cin >> n >> h;
	vector<int> v(n);
	for (int i=0; i<n; i++){
		cin >> v[i];
	}

	int ans = 0;
	for (int i=0; i<n; i++){
		priority_queue<int> que;
		for (int j=0; j<=i; j++){
			que.push(v[j]);
		}
		int num = 0;
		int rh = h;
		while(1) {
			if(!que.empty()) {
				int lt = que.top();
				int rt;
				que.pop();
				if(lt <= rh) {
					num++;
				}
				else {
					num = -1;
					break;
				}
				if(!que.empty()) {
					rt = que.top();
					que.pop();
					if (rt <= rh) {
						num++;
					}
					else {
						num = -1;
						break;
					}
				}
				rh -= max(rt,lt);

			}
			else {
				break;
			}
		}
		ans = max(ans, num);
	}
	cout << ans << endl;
	return 0;
}
