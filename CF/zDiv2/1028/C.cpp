// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int ax[212345];
int ay[212345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
	    int x,y,x2,y2;
		cin>>x>>y>>x2>>y2;
		ax[x]++;
		ax[x2+1]--;
		ay[y]++;
		ay[y2+1]--;
	}


	int ansx = 0;
	int ansy = 0;
	for (int i=1; i<=n; i++){
		ax[i] += ax[i-1];
		ay[i] += ay[i-1];
		int x = ax[i]-ax[i-1];
		int y = ay[i]-ay[i-1];
		cout<<x<<' '<<y<<endl;

		if(x >= n-1 && !ansx){
			ansx = x;
		}
		if(y >= n-1 && !ansy){
			ansy = y;
		}
	}
	cout<<ansx<<' '<<ansy<<endl;


	return 0;
}
