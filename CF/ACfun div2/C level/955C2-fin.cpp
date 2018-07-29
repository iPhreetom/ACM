// CF 955C sad powers
// 	一句话描述：
// 		通过算法把（时间上）不可做变成可做 + 难言其妙的数学世界
// 	知识点：
// 		sqrt
// 			1、返回是一个浮点数
// 			2、当精度不够的时候会四舍五入
// 				经过检测，int类型不会出现精度不够的问题
// 				但是，long long 可能会出现xxx.99999999，得到 xxx+1 的情况
// 			3、解决方案：
// 				浮点型：牛顿菊苣的斜率法（外带魔法常数）——不会
// 				整数型：使用二分法暴力求一个小于等于sqrt（x）的整数
// 		long long
// 			1、当试图用两个int * int 得到一个ll时，会溢出得到负数
// 				解决方案： ll x = 1ll * ......
// 				算数式从左至右，所以先强制变成长整形
// 	总结：
// 		进一步，再进一步，想出解决问题的方法
// 		优化，拆分，把复杂度降低



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll> num;
vector<ll> vals;

ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}

void init(){
	// num.push_back(1);

	// for(int i = 2; i <= 1e6; i++) {
    //     int val = root(i);
    //     if(val * val == i)
    //         continue;
    //     ll a = 1LL * i * i;
    //     int cnt = 0;
    //     while(a <= 1e18 / i) {
    //         a *= i;
    //         cnt++;
    //         if(cnt & 1)
    //             vals.push_back(a);
    //     }
    // }

	for(int i=2;i<=1e6;i++){
		int val = root(i);
        if(val * val == i)
            continue;

		ll t =  1ll * i*i;
		// bug点
		if(t < 0){
			cout<<t<<endl;
			break;
		}
		int cnt=0;
		while(t <= 1e18/i){
			t *= i;
			cnt++;
			// if(root(t)*root(t)!=t);
			if(cnt & 1)num.push_back(t);
		}
	}
	// cout<<num.size()<<endl;
	// cout<<vals.size()<<endl;
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();

	ll q;
	cin>>q;

	while(q--){
		ll l,r;
		cin>>l>>r;
		// cout<<root(r)-root(l-1)+(upper_bound(num.begin(),num.end(),r)-lower_bound(num.begin(),num.end(),l))<<endl;
		cout<<(ll)root(r)-(ll)root(l-1)+(upper_bound(num.begin(),num.end(),r)-lower_bound(num.begin(),num.end(),l))<<endl;
	}

	return 0;
}
