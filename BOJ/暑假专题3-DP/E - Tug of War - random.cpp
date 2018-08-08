// POJ 2576
// 	一句话描述：
// 		来一记随机化大法
// 	知识点：
// 		估计随记贪心可以得到正确答案的概率
// 		如果可以，选择一个不错的贪心策略，然后一发入魂吧
// 	碎碎念：
// 		闲来无事昨天居然睡了一天，顺带玩游戏一天
// 		早上过来听完讲座后，开始看书，看懂了其中的树形DP
// 		然后看了一眼	TIM群 浪费无数时间Orz
// 		还有碎碎念这么好玩，不如放在日记里吧 = w =
// 		集中注意力写题目呀！
//
// 		参加野营的人有N个，现在他们想要分成两波拔河
// 		想要尽可能的公平，所以两边人数一定要对半分（奇数可以多一个人）
// 		体重要尽可能相近，现在问，体重和相差最小是多少
// 		这道题是一道“可行方案的背包问题”，但是因为正解是三重循环
// 		所以数据量不大，因而一发随机化大法可以算出来
// 		所以写完了random - version后，要马上补出背包的版本，一起写出来吧（顺带总结一下可行方案的题目怎么做）

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
#include <ctime>
#define int long long
#define double long double
using namespace std;


// int getCurrentTime()
// {
// 	struct timeval tv;
//
// 	gettimeofday(&tv,NULL);
//
// 	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
// }
vector<int> a;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	int sum  = 0;
	cin>>n;

	for (int i=0; i<n; i++){
		int t;
		cin>>t;
		sum += t;
		a.push_back(t);
	}
	int ans = 1e10;
	if(a.size() % 2 == 1){
		for (int i=0; i<1e5; i++){
			random_shuffle(a.begin(), a.end());
			int l=0,r=0;

			l = a[0];
			for(int i=2;i<a.size();i+=2){
				int mn = min(a[i-1],a[i]);
				int mx = max(a[i-1],a[i]);
				if(l <= r)l += mx , r += mn;
				else r += mx , l+= mn;
			}
			ans = min(l>r?l-r:r-l,ans);
		}
	}
	else{
		for (int i=0; i<1e5; i++){
			random_shuffle(a.begin(), a.end());
			int l=0,r=0;

			for(int i=1;i<a.size();i+=2){
				int mn = min(a[i-1],a[i]);
				int mx = max(a[i-1],a[i]);
				if(l <= r)l += mx , r += mn;
				else r += mx , l+= mn;
			}
			ans = min(l>r?l-r:r-l,ans);
		}
	}
	cout<<(sum-ans)/2<<' '<<(sum+ans)/2<<endl;

	return 0;
}
