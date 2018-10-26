#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
char a[1123];
signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> a;
		int n = strlen(a);

		if(a[n - 1] != '*')
		{

			ans++;
			bool s = 1;
			for(int i = 0; i <= n-1; i++)
			{
				if(a[i] == '*')
				{
					swap(a[i], a[n - 1]);
					s = 0;
					break;
				}
			}
			if(s)
			{
				cout << 0 <<endl;
				continue;
			}
		}

		int cnt = 0;
		for(int i = 0; i < n ;i++)
		{
			if(a[i] != '*')
			{
				cnt ++;
				continue;
			}
			if(cnt > 1)
			{
				cnt--;
				continue;
			}
			if(cnt == 1)
			{
				ans++;
				continue;
			}
			ans += 2;
			cnt = 1;
			continue;
		}

		cout << ans << endl;
	}
	return 0;
}
