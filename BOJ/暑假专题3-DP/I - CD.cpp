// UVA 624
// 	一句话描述：
// 		01背包记录 最优方案
// 	知识点：
// 		利用一个G[I][J]的数组，保存状态转移的时候，选择了前面的一项还是后面的一项
// 		首先初始化全部为0，如果选后面一项，说明“选用了这一个物品”
// 	碎碎念：
// 		啦啦啦，背包的路径会输出裸题01的路径啦
// 		这样的也许就可以解决实际问题了呢
// 		一个CD最长长度为m，给你n个长度的歌曲，请问如何才能够使得歌曲填充尽量的满满呢？
#include<bits/stdc++.h>
// #define int long long
#define double long double
using namespace std;

int m,n;
int f[100005];
bool re[25][100005];
int v[25];

void init(){
	memset(v,0,sizeof(v));
	memset(re,0,sizeof(re));
	memset(f,0,sizeof(f));
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>m>>n){

		init();
		for (int i=1; i<=n; i++){
			cin>>v[i];
		}

		for (int i=n; i>=1; i--){
			for(int j=m; j>=v[i]; j--){
				if(f[j] < f[j-v[i]] + v[i]){
					f[j] = f[j-v[i]] + v[i];
					re[i][j] = 1;
				}
			}
		}

		for (int i=1,j=m; i<=n; i++){
		    if(re[i][j]){
				cout<<v[i]<<' ';
				j -= v[i];
			}
		}
		int sum = f[m];
		cout<<"sum:"<<sum<<endl;
	}
	return 0;
}
