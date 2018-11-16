#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[1123456];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t, n, f;
	cin >> t;
    while(t--)
    {
    	cin >> n >> f;
		for(int i = 0; i < n; i++)
		    cin >> a[i];
		for(int i = 0; i < n; i++)
		{
			int b;
			cin >> b;
			a[i] -= b;
		}
		int s = 0, e = -1, now = f;
		bool sign = 0;
		while(s != (e + 1) % n || !sign)
		{
			e++;
			e %= n;// >= n ? e - n : e;
			now += a[e];
			sign = 1;
			if(now < 0)
			{
				sign = 0;
				while(s != (e + 1) % n && now < 0)
				    now -= a[s++], s %= n;//s >= n ? s - n : s;
				if(s == 0)
				    break;
			}
		}
		//cout << s << ' ' << e << ' ' << now << ' ' << sign << endl;
		if(sign)
		    cout << s + 1 << endl;
		else
		    cout << -1 << endl;
	}
	return 0;
}
