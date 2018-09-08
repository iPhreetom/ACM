#include<bits/stdc++.h>
using namespace std;
char x[500], sign[500];
int num[500];
bool type[500];
int l, n;

char sque[500];
int ls, heads, dnum;

void init()
{
	#define checknum(a) (((a) >= '0' && (a) <= '9') ? 1 : 0)
	l = strlen(x);
	heads = 1;
	dnum = n = ls = 0;
	for(int i = 0; i <= l;)
	{
		if(x[i] == 'd')
		    dnum++;
		//cout << i << endl;
		if(x[i] == '(')
		{
			heads = 1;
			sque[++ls] = x[i++];
			continue;
		}
		if(x[i] == ')')
		{
			heads = 0;
			while(sque[ls] != '(')
			{
				type[++n] = 1;
				sign[n] = sque[ls--];
			}
			ls--;
			i++;
			continue;
		}
		if(x[i] == '\0')
		{
			heads = 0;
			while(ls)
			{
				type[++n] = 1;
				sign[n] = sque[ls--];
			}
			i++;
			continue;
		}

		if(!checknum(x[i]))
		{
			if(heads)
			{
				num[++n] = 0;
				type[n] = 0;
			}
			if(x[i] == '+' || x[i] == '-')
			    while(ls && sque[ls] != '(')
			    {
			    	type[++n] = 1;
				    sign[n] = sque[ls--];
				}
			else
			    while(ls && sque[ls] == '*' || sque[ls] == 'd')
			    {
			    	type[++n] = 1;
				    sign[n] = sque[ls--];
				}
			sque[++ls] = x[i++];
			//cout << ls << ' ' << sque[ls] << endl;
			heads = 0;
			continue;
		}
		num[++n] = 0;
		type[n] = 0;
		while(checknum(x[i]))
			num[n] = num[n] * 10 + x[i++] - 48;
		heads = 0;
	}

}


int main()
{
	while(cin >> x)
	{
		init();
		for(int i = 1; i <= n; i++)
		{
			if(type[i])
			    cout << sign[i] << ' ';
			else
			    cout << num[i] << ' ';
		}
		cout << endl;
	}
}
