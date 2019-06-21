#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=2e5+5;
ll a[maxn], b[maxn], p[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	ll ans = 0, cnt0 = 0, lsp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i]) p[a[i]] = 0;
		else cnt0++;
		if(b[i]) p[b[i]] = i;
	}
	//first, get 1
	//second, play 0 before any card time < id
	//then, play in order
	//spj: 1...i at last in order
	bool ok = 1;
	if(p[1])
	{
		for(int i = p[1]; i <= n; i++)
		{
			if(b[i] != i - p[1] + 1) ok = 0;
		}
	}

	if(ok)
	{
		for(int i = b[n] + 1; i <= n; i++)
		{
			if(p[i] > i - b[n] - 1) ok = 0;
		}
	}
	if(ok)
	{
		cout << n - b[n] << endl;
		return 0;
	}
	ans = p[1];
	for(int i = 2; i <= n; i++)
	{
		if(p[i] - ans > 0) p[i] -= ans;
		else p[i] = 0;
		lsp = max(lsp, p[i] - i + 1);
	}
	ans += lsp;
	ans += n;
	cout << ans << endl;
}
