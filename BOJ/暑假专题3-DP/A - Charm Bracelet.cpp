// POJ 3624
// 	一句话描述：
// 		DP入门，看看，套个模型就能过题系列
// 	知识点：
// 		DP的降低维度是一个重要概念，以后的多重背包就靠降为后的公式一键转化得到

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
#define double long double
using namespace std;

int dp[212345];
int c[4123];
int v[4123];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>c[i]>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=c[i];j--){
			dp[j] = max(dp[j-c[i]]+v[i],dp[j]);
		}
	}

	cout<<dp[m]<<endl;
	return 0;
}
