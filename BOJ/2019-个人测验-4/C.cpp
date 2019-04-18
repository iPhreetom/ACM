#include<bits/stdc++.h>
using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int cs=1; cs<=T; cs++) {
        int d;
        string p;
        cin >> d >> p;


        int cnt = 0;
        int sum = 0;
        int now = 1;
        vector<int> v(p.size(), 0);
        for (int i=0; i<p.size(); i++) {
            if (p[i] == 'S') {
                cnt++;
                sum += now;
                v[i] = now;
            }
            else {
                now *= 2;
            }
        }

        cout << "Case #" << cs << ": ";
        if (cnt > d) {
            cout << "IMPOSSIBLE" << '\n';
        }
        else {
            int ans = 0;
            while (sum > d) {
                for (int i=p.size()-1; i>=1; i--) {
                    if(p[i] == 'S' && p[i-1] == 'C') {
                        sum -= v[i]/2;
                        v[i-1] = v[i]/2;
                        v[i] = 0;
						ans++;
						swap(p[i],p[i-1]);
                        break;
                    }
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
