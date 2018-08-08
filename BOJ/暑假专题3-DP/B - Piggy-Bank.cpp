// hdu1114
// 	一句话描述：
// 		完全背包，一个物品有无数多个
// 	知识点：
// 		只要把01背包写成维度压缩过的形式，
// 		01背包告诫我们的不要顺着推，不然物品会被取多次，就会变成多重背包的正确解的形式
// 		所以写一个“错误的01背包”，就可以解决完全背包的问题啦
// 		状态转移方程真TM有趣
// 	碎碎念：
// 		一个储钱罐装满以后最少有多少钱呢（要求的是完全装满哦）（装满的定义是：其承载重量有上限）
// 		告诉我们有多种重量的硬币，那么最小组合是什么呢！=w=,就是如此裸奔的完全背包问题呢！
// 		不过我现在好想知道如何记录路径呀，想要知道怎么取呀（方案具体是怎么样的呢）
// 		不然只是输出一个答案，现实中解决不了问题，不能够拿来玩呀



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

const int inf = 2e9;
int f[21234];
int c[512];
int v[512];

void init(){
	for (int i=0; i<21234; i++){
		f[i] = inf;
	}
	f[0] = 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		init();
		int e,m;
		cin>>e>>m;
		m-=e;
		if(m <= 0){
			cout<<"This is impossible."<<'\n';
			continue;
		}

		int n;
		cin>>n;
		for (int i=1; i<=n; i++){
		    cin>>v[i]>>c[i];
		}

		for (int i=1; i<=n; i++){
		    for (int j=c[i]; j<=m; j++){
				f[j] = min(f[j],f[j-c[i]]+v[i]);
		    }
		}
		if(f[m] != inf)cout<<"The minimum amount of money in the piggy-bank is "<<f[m]<<".\n";
		else cout<<"This is impossible.\n";
	}
	return 0;
}
