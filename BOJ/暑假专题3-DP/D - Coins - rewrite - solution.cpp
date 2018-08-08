// POJ 1742
// 	一句话描述：
// 		可行解的个数问题
// 	知识点：
// 		通过定义一个好用的状态转移方程，可以通过迭代的方式推出答案呀
// 		如果使用一个维度的数组表示某个解是否可以到达
//
// 		第一个循环枚举物品
// 			for (int i = 1; i <= n; i++)
// 		第二个循环：询问，是否当前的值是可以到达的
// 			for (int j = 0; j <= m; ++j)
//
// 			如果可以到达，那么现在 又可以在这个解的基础上使用 num[i] 个物品了哟
// 				 if (dp[j] >= 0) dp[j] = num[i];
//
// 			如果不能够达到，那么……不如试一试 使用现在的物品能否从它的上一个状态推出来呢（顺着推的哟）
// 				 不能的情况 else if (j < v[i] || dp[j - v[i]] <= 0) dp[j] = -1;
// 				 可以的情况 else dp[j] = dp[j - v[i]] - 1;
// 		（可以通过假设有5个1开推导一下这个思路）
// 		（可是这个思路如何想出来呢，希望某本蓝色的书会告诉我吧）



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

int f[112345];
int n,m;
int v[105];
int num[105];

void init(){
	memset(f,-1,sizeof(f));
	f[0] = 0;
}

void solve(){
	for (int i=1; i<=n; i++){
	    for(int j = 0;j<=m;j++){
			if(f[j] >= 0)f[j] = num[i];
			else if(j<v[i] || f[j-v[i]] < 0)f[j] = -1;
			else f[j] = f[j-v[i]]-1;
		}
	}
	int ans = 0;
	for (int i=1; i<=m; i++){
	    if(f[i] != -1)ans++;
	}
	cout<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		for (int i=1; i<=n; i++){
		    cin>>v[i];
		}
		for (int i=1; i<=n; i++){
		    cin>>num[i];
		}
		init();
		solve();
	}
	return 0;
}
