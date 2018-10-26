// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
//pair<int, string> a[500];
struct{
	int first;
	string second;
	int mn, mj;
} a[500];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;
	string y;
	a[0].mn = 0;
	a[0].mj = 1;
	a[0].second = "";
	a[0].first = 500;
	while(cin >> n)
	{
		if( n == 0)
		    break;
		for(int i = 1; i <= n; i++)
		    cin >>  a[i].second >> a[i].first;
		//sort(a+1, a+n+1);
		//reverse(a+1,a+n+1);
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(a[j].first > a[i].first)
				    swap(a[i], a[j]);
				else if(a[j].first == a[i].first && a[j].second < a[i].second)
				    swap(a[i], a[j]);
			}
			if(a[i].first == a[i-1].first)
			    a[i].mn = a[i - 1].mn, a[i].mj = a[i-1].mj + 1;
			else
			    a[i].mn = a[i-1].mn + a[i-1].mj, a[i].mj = 1;
			cout << a[i].second << ' ' << a[i].first << endl;
		}

		cin >> m;

		for(int i = 1; i <= m; i++)
		{
			cin >> y;
			for(int j = 1; j <= n; j++)
			    if(y == a[j].second)
				 {
					 if(a[j].mj == 1)
					     cout << a[j].mn << endl;
					 else
					     cout << a[j].mn << ' ' << a[j].mj << endl;
					 break;
				 }
		}
	}
	return 0;
}
