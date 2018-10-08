#include<bits/stdc++.h>
//#define int long long
#define double long double
#define endl '\n'
using namespace std;
char a[10][11][10] = { "xxxxx", "....x", "xxxxx", "xxxxx", "x...x", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx", ".....",
					   "x...x", "....x", "....x", "....x", "x...x", "x....", "x....", "....x", "x...x", "x...x", "..x..",
					   "x...x", "....x", "....x", "....x", "x...x", "x....", "x....", "....x", "x...x", "x...x", "..x..",
					   "x...x", "....x", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", "xxxxx",
					   "x...x", "....x", "x....", "....x", "....x", "....x", "x...x", "....x", "x...x", "....x", "..x..",
					   "x...x", "....x", "x....", "....x", "....x", "....x", "x...x", "....x", "x...x", "....x", "..x..",
					   "xxxxx", "....x", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", "....x", "xxxxx", "xxxxx", ".....", };

char x[10][100];
int s[11];
long long add[3];
int out[100];

int check(int t)
{
	memset(s, 0, sizeof s);
	for(int i = 0; i < 7; i++)
	    for(int j = 0; j < 11; j++)
	        if(strcmp(x[i] + t * 6, a[i][j]) == 0)
	            s[j]++;
	for(int i = 0; i < 11; i++)
	    if(s[i] == 7)
	        return i;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i = 0; i < 7; i++)
        cin >> x[i];
    int n = (strlen(x[1]) + 1) / 6;
    for(int j = 0; j < 7; j++)
    	for(int i = 1; i <= n; i++)
        	x[j][i * 6 - 1] = '\0';

    int now = 1;
    for(int i = 0; i < n; i++)
    {
    	int tmp = check(i);
    	if(tmp == 10)
    	{
    		now = 2;
    		continue;
		}
		add[now] = add[now] * 10 + tmp;
	}
	add[1] += add[2];
	int l = 0;
	while(add[1] != 0)
	{
		out[++l] = add[1] % 10;
		add[1] /= 10;
	}
	if(l == 0)
	    l = 1;
	for(int i = 0; i < 7; i++)
	{
		for(int j = l; j > 0; j--)
		{
			cout << a[i][out[j]];
			if(j != 1)
			    cout << '.';
		}
		cout << endl;
	}

    return 0;
}
