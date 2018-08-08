// POJ 1276
// 	一句话描述：
// 		多重背包——二进制优化
// 	知识点：
// 		一个数 x 可以拆分成 2的进制部分 和 剩余部分
// 		1-2^n 的递增二进制部分可以表示 2^(N+1) 一下的所有数，加上剩余部分，则可以表示 x 以内的任意数
// 		所以把 一个有num[i]件的物品 转换为 1件 2件 4件 8件…… 剩余件 的多个物品，则每个物品只有一个，就变成01背包啦
// 	碎碎念：
// 		现在有一个会吐出现金的ATM哟
// 		其中有N中面额的纸币，每种有num[i]张，
// 		如果需要取出一个整数金额 x 那么，请问ATM在保证吐出的钱不超过X的情况下，最多能够给你多少现金呢？
//
// 		显然，这道题的取出金额就是背包的容量，而多张纸币，直接二进制分割，就可以看作01背包了，在背包容量有限的情况下，你最多会取走多少钱呢
// 		其中这道题的 代价 同时也是 价值，很奇妙的性质
// 		—— 其代价就是其价值。
// 		如同哲学的句子，在时空中流转。

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
#define int long long
#define double long double
using namespace std;

int m,n;
int dp[112345];
vector<int> v;
vector<int> c;

void divide(int number,int val){
	int temp = 1;
	while(temp <= number){
		v.push_back(temp*val);
		c.push_back(temp*val);
		number -= temp;
		temp *= 2;
	}

	if(number != 0){
		v.push_back(number*val);
		c.push_back(number*val);
	}
}

void init(){
	memset(dp,0,sizeof(dp));
}

void solve(){

	for (int i=0; i<v.size(); i++){
		for(int j=m;j>=c[i];j--){
			dp[j] = max(dp[j],dp[j-c[i]]+v[i]);
		}
	}

	cout<<dp[m]<<endl;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>m){
		c.clear();
		v.clear();
		cin>>n;
		for (int i=0; i<n; i++){
			int number,val;
			cin>>number>>val;
		    divide(number,val);
		}
		init();
		solve();
	}
	return 0;
}
