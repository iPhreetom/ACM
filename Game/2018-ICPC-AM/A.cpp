#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
int a[1123456], d, s, cnt;
void getfirst(int wei)
{
	int s1 = s;
	a[0] = 0;
	while(s1 > 9)
	{
		a[++a[0]] = 9;
		s1 -= 9;
	}
	a[++a[0]] = s1 - 1;
	for(int i = a[0] + 1; i < wei; i++)
	    a[i] = 0;
	a[wei] = 1;
	a[0] = wei;
}
void findnext()
{
	int s0 = 0;
	//cout << a[0] << endl;
	for(int i = 1; i <= a[0]; i++)
	{
		if(s0 == 0)
		{
			if(a[i] != 0)
				s0 = i;
			//cout << s0 << ' ';
			continue;
		}

		if(a[i] != 9)
		{
			a[i]++;
			a[s0]--;
			return ;
		}
	}
	//cnt++;
	getfirst(a[0] + 1);
}
void getfirst()
{
	int s1 = s;
	while(s1 > 9)
	{
		a[++a[0]] = 9;
		s1 -= 9;
	}
	a[++a[0]] = s1;
}
bool check()
{
    int ys = 0;
    for(int i = a[0]; i >= 1; i--)
    	ys = (ys * 10 + a[i]) % d;

    if(ys == 0)
        return 1;
    return 0;
}
void printnum()
{
	for(int i = a[0]; i >= 1; i--)
	    cout << a[i];
	cout << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> d >> s;
	getfirst();
	//printnum();
	while(!check())
	{
		findnext();
		printnum();
		//if(cnt == 4)
		//    break;
	}
	if(cnt != 4)
	    printnum();
	else
	    cout << -1 << endl;
	return 0;
}
