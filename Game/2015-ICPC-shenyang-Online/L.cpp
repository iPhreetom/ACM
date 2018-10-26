// fyttql
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int TT, T;
	cin >> TT;
	for(int  T = 1; T <= TT; T++)
	{
		int n, a, b, x, y;
		int mx, mn, imx, imn;
		int umx, umn, uimx, uimn;
		int mx2, mn2, imx2, imn2;
		int umx2, umn2, uimx2, uimn2;
		cin >> n >> a >> b;
		cin >> x;
		y = x * x;
		mx = mn = x;
		imx = imn = y;
		umx = umn = uimx = uimn = 1;

		cin >> x;
		y = x * x;
		mx2 = mn2 = x;
		imx2 = imn2 = y;
		umx2 = umn2 = uimx2 = uimn2 = 2;

		if(mx2 > mx) swap(mx, mx2), swap(umx,umx2);
		if(mn2 < mn) swap(mn, mn2), swap(umn, umn2);
		if(imx2 > imx) swap(imx, imx2), swap(uimx, uimx2);
		if(imn2 < imn) swap(imn, imn2), swap(uimn, uimn2);

		for(int i = 3; i <= n; i++)
		{
			cin >> x;
			y = x * x;
			if(x > mx) mx2 = mx, mx = x,  umx2 = umx, umx = i;
			else if(x > mx2) mx2 = x, umx2 = i;

			if(x < mn) mn2 = mn, mn = x, umn2 = umn, umn = i;
			else if(x < mn2) mn2 = x, umn2 = i;

			if(y > imx) imx2 = imx, imx = y,   uimx2 = uimx, uimx = i;
			else if(y > imx2) imx2 = y, uimx2 = i;
			if(y < imn) imn2 = imn, imn = y, uimn2 = uimn, uimn = i;
			else if(y < imn2) imn2 = y, uimn2 = i;
		}
		int ans = 0, ans2 = 0, used;

		if(a > 0)
			ans += imx * a, used = uimx;
		else
			ans += imn * a, used = uimn;
		if(b > 0)
		{
			if(used != umx)
				ans += mx * b;
			else
				ans += mx2 * b;
		}
		else
		{
			if(used != umn)
				ans += mn * b;
			else
				ans += mn2 * b;
		}
		ans2 = ans;
		ans = 0;
		if(b > 0)
		    ans += mx * b, used = umx;
		else
		    ans += mn * b, used = umn;
		if(a > 0)
		{
			if(used != uimx)
			    ans += imx * a;
			else
			    ans += imx2 * a;
		}
		else
		{
			if(used != uimn)
			    ans += imn * a;
			else
			    ans += imn2 * a;
		}
		if(ans < ans2) ans = ans2;
		cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}
