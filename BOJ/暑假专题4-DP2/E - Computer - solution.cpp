// HDU 2196
// 	一句话描述：
// 		树形DP，求树上任意一点 的最远点
// 	知识点：
// 		说白一点就是树上DFS
// 		多次DFS顺推，逆推，记录某些有用的信息
// 	碎碎念：
// 		显然，求树上求两次最远点就可以得到直径的长度
// 			但是，对于树上任意一个节点，把某一条固定的直径两个端点，当作是它的最远点是不对的
// 			它的最远点一定是“圆周”上的点，
// 			但是“圆周”上的点不一定是它的最远点
// 		一个下午就交代给你这个树形DP了，该死的DFS，思路想出来以后居然敲出来了这么多BUG
// 		或者说，敲的时候没想清楚
// 		乱敲了很多东西
// 		在想出大致思路后，在实现时，容易忘记具体的细节是要怎么实现，这怎么办呢？
// 		不如祭出函数大法？
// 		还是祭出草稿大法，在敲一道题前，现在草稿纸上用图纸写出大概的数组使用，状态推导？（针对图论，或者DP？）
// 		不知道……下一次……下一次敲图论或者动态规划的题目时候，我要先试试
// 			草稿大法
// 			并且同时使用函数大法
//
//
// 		似乎题解：
// 		给你一个树的节点个数
// 		并且给你N-1条边，和边的长度
// 		接下来请你输出对于每一个节点离它最远的节点的距离
//
// 		如果随意找一个节点开始DFS，那么问题显然会变成
// 			对于一个节点，在向上走和向下走谁会走得更远的问题
// 		首先通过第一次的DFS，找到每个节点向下走的最长距离 和 次长距离
// 		然后第二次DFS时，找到每个节点想上走的最长距离
// 		最后for循环输出较大的那个答案

#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
struct node{
	int mxf=0;
	int mxd=0;
	int index=0;
	int mxd2=0;
	int index2=0;
	int father=0;
	vector<pair<int,int>> son;
};
vector<node> mp(11234);
bitset<11234> vis;
int disfather[11234];
int deep2[11234];

void init(){
	mp.clear();
	mp.resize(21234);
	vis = 0;
	memset(disfather,0,sizeof(disfather));
	memset(deep2,0,sizeof(deep2));

}

int dfs(int index,int father,int deep){
	vis[index] = 1;
	deep2[index] = deep;
	disfather[index] = deep-deep2[father];
	for (int i=0; i<mp[index].son.size(); i++){
		if(!vis[mp[index].son[i].first]){
			int t = dfs(mp[index].son[i].first,index,deep+mp[index].son[i].second)+mp[index].son[i].second;
			if(mp[index].mxd < t){
				mp[index].mxd2 = mp[index].mxd;
				mp[index].index2 = mp[index].index;
				mp[index].mxd = t;
				mp[index].index = mp[index].son[i].first;
			}
			else if(mp[index].mxd2 < t){
				mp[index].mxd2 = t;
				mp[index].index2 = mp[index].son[i].first;
			}
		}
	}
	return mp[index].mxd;
}

void dfsfather(int index,int father){
	vis[index] = 1;
	int &mxf = mp[index].mxf;
	if(mp[father].son.size() == 1){
		mxf = disfather[index] + mp[father].mxf;
	}
	else{
		if(mp[father].index == index){
			mxf = max(mp[father].mxd2,mp[father].mxf)+disfather[index];
		}
		else{
			mxf = max(mp[father].mxd,mp[father].mxf)+disfather[index];
		}
	}
	for (int i=0; i<mp[index].son.size(); i++){
		if(!vis[mp[index].son[i].first])dfsfather(mp[index].son[i].first,index);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>n){
		init();
		node n1;
		for (int i=2; i<=n; i++){
		    int f,c;
			cin>>f>>c;
			mp[i].son.push_back(make_pair(f,c));
			mp[f].son.push_back(make_pair(i,c));
		}
		dfs(1,0,0);
		vis = 0;
		vis[1] = 1;
		for (int i=0; i<mp[1].son.size(); i++){
		    dfsfather(mp[1].son[i].first,1);
		}
		for (int i=1; i<=n; i++){
		    cout<<max(mp[i].mxd,mp[i].mxf)<<'\n';
		}
	}
	return 0;
}
