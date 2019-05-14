#include<iostream>
#include<cstdio>
#define int long long
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	double a,b,r;
	char op;
	scanf("%lf %c %lf",&a,&op,&b);
	if (op == '+') r = a+b;
	if (op == '-') r = a-b;
	if (op == '*') r = a*b;
	printf("%.0lf\n",r);
	return 0;
}
