#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
typedef long long LL;


LL n , l , r , a[60] , b[60] , ans;

void dfs(LL x , LL i)
{
	if (x > 1)
	{
		dfs(x/2,i+1);
		a[i] = a[i+1]*2+1;
		b[i] = b[i+1]*2;
		if (x%2) b[i]++;
	}
	else a[i] = b[i] = 1;
}

LL check(LL x , LL i)
{
	if (x <= a[i+1]) return check(x,i+1);
	if (x == a[i+1]+1) return b[i]-b[i+1];
	if (x > a[i+1]+1) return check(x-a[i+1]-1,i+1)+b[i]-b[i+1];
}

int main()
{
	cin >> n >> l >> r;
	dfs(n,1);
	cout << check(r,1)-check(l-1,1) << "\n";
	return 0;
}
