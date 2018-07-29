// 使用auto i = chrono::system_clock::now()
// 使用 chrono::duration<double> diff = i-h;
// 使用 diff.count()*1000
//
//
// ceil() 向上取整（天花板）
// round() 四舍五入
// floor() 向下取整（地板）

/*—————————————————————— 标志：开始进入DIV后两题阶段 ————————————————*/
// 01分数规划
	// dp 与 二分答案
	// https://www.cnblogs.com/Hallmeow/p/7750483.html 01分数规划
	// http://www.cnblogs.com/perseawe/archive/2012/05/03/01fsgh.html 01分数规划

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
struct info{
	double cost;
	double proce;
	double v;
	// double percost;
	// bool c=0;
};
info a[55];

double arr[55];
double ans = 1e18;

int main(){
	srand(time(0));
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].cost;
	for(int i=0;i<n;i++)cin>>a[i].proce;

	ll l=1,r=1e13;
	while(l+1 < r){
		ll mid = l + (r-l)/2;
		// check f(l) < 0
		// if(check(mid))
	}

	return 0;
}
