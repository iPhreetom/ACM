#include<bits/stdc++.h>
//#define int long long
#define double long double
#define endl '\n'
using namespace std;
int n;
int a[212345];
int s[212345];
int r[212345];
# define pii pair<int, int>
//priority_queue<pii,vector<pii >, greater<pii > > Q;
int q[212345], ql, qs;

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1; i <= 2 * n; i++){
    	cin >> a[i];
    	r[a[i]]++;
	}
	for(int i = 1; i <= 2 * n; i++)
	    if(r[i] == 0)
	        q[++ql] = i;
	//cout <<ql << endl;

	for(qs = 1; qs <= ql; qs++)
	{
		int now = q[qs];

		if(s[now] != 0)
		    continue;

		s[now] = 1;
		s[a[now]] = -1;

		int to = a[a[now]];
		r[to]--;

		if(r[to] == 0)
		    q[++ql] = to;
	}

	for(int i = 1; i <= n; i++)
	    if(s[i] == 0 || s[i] == 1)
	        cout << i << ' ';

	for(int i = n + 1; i <= n + n; i++)
	    if(s[i] == 1)
	        cout << i << ' ';
	cout << endl;
    return 0;
}
// 5
// 6 7 6 7 10
// 2 1 2 4 5
