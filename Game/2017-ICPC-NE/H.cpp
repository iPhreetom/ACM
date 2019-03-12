#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	while(n -- ) {
		vector<int> v(3, 0);
		for (int i=0; i<3; i++) {
		    cin >> v[i];
		}

		int d;
		cin >> d;

		sort(v.rbegin(),v.rend());
		int ans = (v[0]+d)*(d+v[0]) + v[1]*v[1] + v[2]*(v[2]+7);
		int cnt = 0;
		while (d > 0) {
			int a1 = (v[0]+1)*(v[0]+1) + v[2]*(v[2]+7) + v[1]*v[1];
			int a2 = v[0]*v[0] + v[1]*v[1] + (v[2]+1)*(v[2]+1) + 7*min(min(v[2]+1,v[1]),v[0]);

			cnt++;
			if(a1 >= a2) {
				if(d >= 2) {
					int a3 = v[0]*v[0] + (v[1]+1)*(v[1]+1) + (v[2]+1)*(v[2]+1) + 7*min(min(v[2]+1,v[1]+1),v[0]);
					int a4 = (v[0]+2)*(v[0]+2) + v[1]*v[1] + v[2]*(v[2]+7);
					if(a3 > a4) {
						int now = (v[0]-2+d)*(d-2+v[0]) + (v[1]+1)*(v[1]+1) + (v[2]+1)*(v[2]+1) + 7*min(min(v[2]+1,v[1]+1),v[0]);;
						d-=2;
						v[1]++;
						v[2]++;
						sort(v.rbegin(),v.rend());
						ans = max(ans,now);
					}
					else {
						int now = (v[0]+d)*(d+v[0]) + v[1]*v[1] + v[2]*(v[2]+7);
						ans = max(ans,now);
					}
				}
				else {
					int now = (v[0]+d)*(d+v[0]) + v[1]*v[1] + v[2]*(v[2]+7);
					ans = max(ans,now);
				}
			}
			else {
				// cout << "cnt = " << cnt << endl;
				v[2] ++;
				d --;
				sort(v.rbegin(),v.rend());
				int now = (v[0]+d)*(d+v[0]) + v[1]*v[1] + v[2]*(v[2]+7);
				ans = max(now, ans);
			}
			if(cnt > 1000)break;
		}
		cout << ans << endl;
	}
	return 0;
}
