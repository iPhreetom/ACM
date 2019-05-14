#include<bits/stdc++.h>
//#define endl "\n"
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
#define pb push_back
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string ans;
		vector<int> v[50];
		for (int i = 0; i < 119; i++)
		{
			cout << i * 5 + 1 << endl;
			char ch;
			cin >> ch;
			v[ch - 'A'].pb(i);
		}
		for (int i = 0; i < 5; i++)
		{
			if (v[i].size() < 24)
			{
				ans.pb('A' + i);
				break;
			}
		}
		for (int i = 0; i < 23; i++)
		{
			cout << v[ans[0] - 'A'][i] * 5 + 2 << endl;
			char ch;
			cin >> ch;
			v[ch - 'A' + 5].pb(i);
		}
		for (int i = 5; i < 10; i++)
		{
			if (i + 'A' == ans[0]) continue;
			if (v[i].size() < 6)
			{
				ans.pb('A' + i);
				break;
			}
		}
		for(int i = 0; i < 5; i++)
		{
			cout << v[ans[1] - 'A'][i] * 5 + 3 << endl;
			char ch;
			cin >> ch;
			v[ch - 'A' + 10].pb(i);
		}
		for (int i = 10; i < 15; i++)
		{
			if (i + 'A' == ans[0] || i + 'A' == ans[1]) continue;
			if (v[i].size() == 1)
			{
				ans.pb('A' + i);
				ans.pb('F');
				ans.pb('A' + v[i][0]);
				break;
			}
		}
		for(int i = 0; i < 5; i++)
		{
			if(ans[0] == 'A' + i) continue;
			if(ans[1] == 'A' + i) continue;
			if(ans[2] == 'A' + i) continue;
			if(ans[4] == 'A' + i) continue;
			ans[3] == 'A' + i;
		}
		cout << ans << endl;
		cin >> ans;

	}
}
// 2
// 4
// RSRSRS
// RPSPSS
// SRSRSR
// SPRPRR
// 4
// RSRSRS
// RPS
// SRS
// SPR
//
//
