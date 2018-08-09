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

int n;
const int maxn = 5e4+5;
int head[maxn]; // 起点编号 ——> 空间位置
int ver[maxn]; // 空间位置 ——> 重点编号
int nt[maxn]; // 空间位置 ——> 下一个空间位置
int edge[maxn]; // 空间位置 ——> 值
int tot; // 空间位置递增

void add(int x,int y,int v){// 在头部插入
	nt[++tot] = head[x] , head[x] = tot;
	ver[tot] = y;
	edge[tot] = v;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	int mx=0;
	for (int i=0; i<n; i++){
		int l,r,c;
		cin>>l>>r>>c;
		add(r,l,-c);
		mx = max(mx,r);
	}
	for (int i=0; i<=mx; i++){
		add(i,i+1,1);
	}
	for (int i=1; i<=mx; i++){
		add(i+1,i,0);
	}

	return 0;
}
