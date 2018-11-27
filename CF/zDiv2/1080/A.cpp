// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int red = n*2;
	int green = 5*n;
	int blue = 8*n;
	cout<< 3 + (red-1)/m + (green-1)/m +( blue-1)/m <<endl;
	return 0;
}
