// POJ 1125（Floyd最优起点）
// 	一句话描述：
// 		Floyd 的暴力n^3算法
// 	知识点：
// 		Floyd本质上是一种动态规划
// 		直白的理解：
// 			易得：在k=1时，我们得到了所有通过1相连的边
// 			疑惑：如果两个点要通过1，才能相连，但是在更新1的时候，前面的点还没有连起来
// 				怎么办呢？
// 			解答：
// 				因为，1所连着的点都更新了【与1直接相连的边】
// 				所以如果要更新【通过1的边】，那么只需要通过那些【与1直接相连的点】就可以了
// 				并且，我们可以推断出【与1直接相连，且被更新】的点，一定是没有被K遍历到的
// 	碎碎念：
// 		这道题看错了很多次
// 			首先是直接敲了一个最小生成树上去，敲完才发觉不对劲
// 			think twice ， code once
// 			在没想清楚的时候，开始说，开始敲
// 			是很糟糕的事情，下一次要怎么处理呢？
//
// 			这道题目的题面很长
// 			所以注意力不集中，但是就算再长，我觉得也可以一行一行的读下去
// 			再其中遇到不好理解的句子，先预判一下它是否与答案相关
// 			查单词，以及很多事情，都可以试试
//
// 			最后输出的一些提示，我没有看到
// 			这件事情已经发生了两次了
// 			上一次是没有看到保留两位小数
// 			这一次是没看到disjoint
//
// 		似乎题解：
// 			现在你被委任去做一件坏事
// 			通过 传播谣言 打击华尔街的证劵所
// 			每个交易员 可以对 另一些交易员传播信息，并且传播出去的时间各不相同
// 			现在要求你选出一个交易员作为你第一个传播谣言的对象，
// 			使得谣言传遍所有交易员的时间最短（最长路最短）
//
// 			显然，这道题没有什么明显的优化方法
// 			我们需要遍历每一个交易员作为起点，得到最长路
// 			再求出最短路
// 			我们这么一想，就可以看出Floyd虽然有点慢，但是这道题中它的复杂度是可以接受的
// 			并且很好敲



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

int mp[105][105];

void init(){
	memset(mp,0x3f,sizeof(mp));
	// memset 只能够把所有位置填一样的数字？
	for (int i=0; i<105; i++){
	    mp[i][i]=0;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	while(1){
		init();
		cin>>n;

		if(n == 0)break;
		for (int i=1; i<=n; i++){
		    int k;
			cin>>k;
			for (int j=0; j<k; j++){
			    int v,c;
				cin>>v>>c;
				mp[i][v]=min(c,mp[i][v]);
			}
		}

		for(int k = 1;k<=n;k++){
			for (int i=1; i<=n; i++){
			    for (int j=1; j<=n; j++){
			        mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
			    }
			}
		}
		int mn = 0x3f;
		int index = 0;
		for (int i=1; i<=n; i++){
			int sum = 0;
		    for (int j=1; j<=n; j++){
				sum = max(mp[i][j],sum);
		    }
			if(sum <= mn){
				index = i;
				mn = sum;
			}
		}
		if(mn != 0x3f)cout<<index<<' '<<mn<<endl;
		else cout<<"disjoint"<<endl;
		// for (int i=0; i<105; i++){
		//     for (int j=0; j<105; j++){
		//         cout<<mp[i][j]<<' ';
		//     }cout<<endl;
		// }
	}
	return 0;
}
