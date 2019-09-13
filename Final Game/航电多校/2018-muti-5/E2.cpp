// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
#include<iostream>
#include<cmath>
using namespace std;

#define pi acos(-1.0)

typedef struct node
{
	int x;
	int y;
}point;

double add(point a, double r1, point b, double r2)
{
	double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (d >= r1+r2)
		return 0;

	bool sw = 0;
	if (r1>r2)
	{
		sw = 1;
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}

	if(r2 - r1 > d)
		return 0;

	double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	// cout<<"ang1 = "<<ang1<<endl;
	// cout<<"ang2 = "<<ang2<<endl;

	if (!sw) return -ang1*r1*2 + ang2*r2*2;
	else return ang1*r1*2 - ang2*r2*2;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int m,R;
		cin >> m >> R;
		point a;
		a.x = 0;
		a.y = 0;

		double len = R*2*pi;
		for (int i=0; i<m; i++){
			point b;
			cin >> b.x >> b.y;
			double r;
			cin >> r;
			len += add(a,R,b,r);
		}
		cout << fixed << setprecision(9) << len << endl;
	}
	return 0;
}
