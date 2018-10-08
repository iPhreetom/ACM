// genius
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
int a[112345], b[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, now = 0, del = 0, ans = 0;
        cin >> n >> m;
        memset(a, 0, sizeof a);
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if(x > now)
            {
                a[i + m - 1] = x - now;
                now = x;
            }
            else
            {
                del += now - x;
                now = x;
            }

            if(a[i] != 0)
            {
                del -= a[i];
                if(del < 0)
                {
                    ans += -1 * del;
                    now -= -1 * del;
                    del = 0;
                }
            }
            cout << i << ' ' << now << ' ' << del << ' ' << ans << endl;
        }
        cout << ans << endl;
    }

	return 0;
}

