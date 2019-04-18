// fyt
#include<bits/stdc++.h>
#define double long double
#define endl '\n'
using namespace std;

bool lis[612];
int lt[612];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int m,t,r;
	cin >> m >> t >> r;
	vector<int> a(m+1);
	for (int i=1; i<=m; i++){
		cin >> a[i];
	}

	if (t < r) {
		cout << -1 << endl;
	}
	else {
		int ans = 0;
		for (int i=1; i<=m; i++){
			if(lt[a[i]] < r) {
				ans += (r-lt[a[i]]);
				int tr = (r-lt[a[i]]);
				// cout<<"tr = "<<tr<<endl;
				for (int j=0; j<tr; j++){
					for (int k=a[i]-tr+1+j; k<=a[i]-tr+t+j; k++) {
						if(k<0)continue;
						lt[k]++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	// for (int i=1; i<=a[m]; i++){
	//     cout<<lt[i]<<' ';
	// }cout<<endl;
	return 0;
}
