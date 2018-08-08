// wa

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
// #define int long long
#define double long double
using namespace std;

int f[105][112345];
int n,m;
int v[105];
int num[105];

void init(){
	memset(f,-1,sizeof(f));
	f[0][0] = 0;
}

void solve(){
	for (int i=1; i<=n; i++){
		for (int j=0; j<=m; j++){
			if(f[i-1][j] >= 0){
				f[i][j] = num[i];
			}
			else{
				f[i][j] = -1;
			}
		}
		for (int j=0; j<=m-v[i]; j++){
			if(f[i][j] > 0){
				f[i][j+v[i]] = max(f[i][j+v[i]],f[i][j]-1);
			}
		}
	}
	int ans = 0;
	for (int i=1; i<=m; i++){
		if(f[n][i] != -1){
			ans++;
		}
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		for (int i=0; i<n; i++){
		    cin>>v[i];
		}
		for (int i=0; i<n; i++){
		    cin>>num[i];
		}
		init();
		solve();
	}
	return 0;
}
