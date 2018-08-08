
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
#include<unordered_map>
#include<unordered_set>
#define int long long
#define double long double
using namespace std;

int m,n;
int dp[112345];
vector<int> v;
int tpn[213];
int tpv[213];
unordered_map<int,int> ans;

void divide(int number,int val){
	int temp = 1;
	while(temp <= number){
		v.push_back(temp*val);
		// c.push_back(temp*val);
		number -= temp;
		temp *= 2;
	}

	if(number != 0){
		v.push_back(number*val);
		// c.push_back(number*val);
	}
}

void init(){
	memset(dp,0,sizeof(dp));
}

void solve(){

	for (int i=0; i<v.size(); i++){
		for(int j=m;j>=v[i];j--){
			dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
		}
	}

	// for (int i=0; i<=m; i++){
	//     cout<<dp[i]<<' ';
	// }cout<<endl;

	for (int i=1; i<=m; i++){
		if(dp[i] != 0){
			ans[dp[i]]++;
		}
	}
	cout<<ans.size()<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n){
		v.clear();
		ans.clear();
		cin>>m;
		if(n == 0 && m == 0){
			break;
		}
		for (int i=0; i<n; i++){
		    cin>>tpv[i];
		}
		for (int i=0; i<n; i++){
		    cin>>tpn[i];
		}

		for (int i=0; i<n; i++){
		    divide(tpn[i],tpv[i]);
		}
		init();
		solve();
	}
	return 0;
}
