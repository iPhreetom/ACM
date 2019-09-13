// fyt
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    int n,m,k;
    while (t--) {
        cin >> n >> m >> k;
        int res = m%(n-k+1);
        int num = k+res;
        if (res == 0) {
            num = n;
        }

        int m1;
        if (k==1) {
            m1 = min(m+1, n*(m/(n-k+1)+1));
        }
        else m1 = min(k*(m+1), (m/(n-k+1)+1)*num );
        cout << m1 << endl;
    }
    return 0;
}
