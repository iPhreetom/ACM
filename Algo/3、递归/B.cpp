#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;

int t;
int ans = 0;
bool dp[93][93][93];

void digui(int x,int y,int z){
	if(dp[x][y][z])return;
	dp[x][y][z] = 1;

	if(pow(3,x)*pow(5,y)*pow(7,z) <= t){
		ans++;
		digui(x+1,y,z);
		digui(x,y+1,z);
		digui(x,y,z+1);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>t;

	digui(1,0,0);
	digui(0,1,0);
	digui(0,0,1);
	cout<<ans<<endl;
	return 0;
}
