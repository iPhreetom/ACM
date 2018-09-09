#include<bits/stdc++.h>
using namespace std;
#define pls 105
int f[1200][300];
int a[1200][5];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int s, n, bad, good;
	cin >> n >> s >> bad >> good;
	for(int i = 1; i <= n; i++)
	    cin >> a[i][1] >> a[i][2] >> a[i][3];
	for(int i = -100; i <= bad; i++)
	    f[n + 1][i + pls] = -1;
	for(int i = good; i <= 100; i++)
	    f[n + 1][i + pls] = 1;

	for(int i = n; i > 0; i--)
	{
		if(i % 2)
		{
			for(int j = -100; j <= 100; j++)
			{
			    int x, y, z;
			    if(a[i][1] != 0)
			    {
			    	x = j + a[i][1];
			    	x = x > 100 ? 100 : x;
			    	x = x < -100 ? -100 : x;
			    	x = f[i + 1][x + pls];
				}
				else
				    x = -1;
				if(a[i][2] != 0)
			    {
			    	y = j - a[i][2];
			    	y = y > 100 ? 100 : y;
			    	y = y < -100 ? -100 : y;
			    	y = f[i + 1][y + pls];
				}
				else
				    y = -1;
				if(a[i][3] != 0)
			    {
			    	z = j * (-1);
			    	z = f[i + 1][z + pls];
				}
				else
				    z = -1;
				if(x == 1 || y == 1 || z == 1)
				    f[i][j + pls] = 1;
				else if(x == 0 || y == 0 || z == 0)
				    f[i][j + pls] = 0;
				else
				    f[i][j + pls] = -1;
			}
		}
		else
		{
			for(int j = -100; j <= 100; j++)
			{
			    int x, y, z;
			    if(a[i][1] != 0)
			    {
			    	x = j + a[i][1];
			    	x = x > 100 ? 100 : x;
			    	x = x < -100 ? -100 : x;
			    	x = f[i + 1][x + pls];
				}
				else
				    x = 1;
				if(a[i][2] != 0)
			    {
			    	y = j - a[i][2];
			    	y = y > 100 ? 100 : y;
			    	y = y < -100 ? -100 : y;
			    	y = f[i + 1][y + pls];
				}
				else
				    y = 1;
				if(a[i][3] != 0)
			    {
			    	z = j * (-1);
			    	z = f[i + 1][z + pls];
				}
				else
				    z = 1;
				if(x == -1 || y == -1 || z == -1)
				    f[i][j + pls] = -1;
				else if(x == 0 || y == 0 || z == 0)
				    f[i][j + pls] = 0;
				else
				    f[i][j + pls] = 1;
			}
		}

	}
	if(f[1][s + pls] == 1)
	    cout << "Good Ending" << endl;
	if(f[1][s + pls] == 0)
	    cout << "Normal Ending" << endl;
	if(f[1][s + pls] == -1)
	    cout << "Bad Ending" << endl;
	return 0;
}
/*
3 90 100 -80
10 70 1
*/
