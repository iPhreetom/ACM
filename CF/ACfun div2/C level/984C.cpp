// CF 984C Finite of not
//
// 数论
// 进制转换
// 知识点：
// 	思路：10进制转换成为另一个进制 ：主要看，小数（分数形式）的分母在另一个进制能否表示
// 	转换法： 先转换成10进制，然后通过除法进行转换：整数除余 ， 小数乘取
	// 技巧： 在判断一个数的约数是否全部包含在另一个数中
	// 	通过不断的刷GCD得到，余数，把 另一个数 更新为余数
	// 	因为得到的最小公约数，包含了接下来所需要的所有质因数，其余的值都是不需要的
	// 		（优化）
// 		gcd的复杂度：log(n)
#pragma GCC diagnostic error "-std=c++11"
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

long long p,q,b,n;

long long gcd(long long a,long long b){
	long long c ;
	while(a!=0){
		//辗转相除
		c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p>>q>>b;
		if(q == p || p == 0 || q == 1){
			cout<<"Finite"<<endl;
		}
		else{
			long long t = gcd(p,q);
			q /= t;

			long long res=b;

			//被卡TLE在这里
			//我为什么想不到这个算法
			while(q!=1 && res !=1){
				res = gcd(res,q);
				q /= res;
			}

			if(q == 1){
				cout<<"Finite"<<endl;
			}
			else{
				cout<<"Infinite"<<endl;
			}
		}

	}
	return 0;
}
