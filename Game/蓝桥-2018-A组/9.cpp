#include<bits/stdc++.h>
using namespace std;

int m1[1123], m2[1123], m3[1123];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i=0; i<1001; i++) {
	    m1[i] = -1;
		m2[i] = -1;
		m3[i] = -1;
	}

	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int t;
	    cin >> t;
		int mt = t%k;
		// if (m1[mt] == -1) {
		// 	m1[mt] = t;
		// }
		if(m1[mt] <= t) {
			m3[mt] = m2[mt];
			m2[mt] = m1[mt];
			m1[mt] = t;
		}
		// else if(m2[mt] == -1) {
		// 	m2[mt] = t;
		// }
		else if(m2[mt] <= t){
			m3[mt] = m2[mt];
			m2[mt] = t;
		}
		// else if(m3[mt] == -1) {
		// 	m3[mt] = t;
		// }
		else if(m3[mt] <= t) {
			m3[mt] = t;
		}
	}
	int ans = 0;
	for (int i=0; i<k; i++) {
	    if((3*i)%k == 0 && m1[i] != -1 && m2[i] != -1 && m3[i] != -1) {
			ans = max(ans, m1[i]+m2[i]+m3[i]);
		}
		if(m1[i] != -1 && m2[i] != -1) {
			int res = k - (2*i)%k;
			if(res != i && m1[res] != -1) {
				ans = max(ans, m1[i] + m2[i] + m1[res]);
			}
		}
		if(m1[i] != -1) {
			for (int j=0; j<i; j++) {
				if(m1[j] != -1) {
					int res = k - (i+j)%k;
					if(res == i) {
						if(m2[i] != -1){
							ans = max(ans, m1[i]+m2[i]+m1[res]);
						}
					}
					else if(res == j) {
						if(m2[j] != -1) {
							ans = max(ans, m1[i]+m1[j]+m2[j]);
						}
					}
					else {
						if(m1[res] != -1){
							ans = max(ans, m1[i]+m1[j]+m1[res]);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
