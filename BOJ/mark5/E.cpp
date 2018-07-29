
#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	if(n == 1 || n == 2){
		cout<<"-1"<<endl;
	}
	else{
		if(n %2 == 1){
			cout<<(n*n-1)/2<<' '<<(n*n-1)/2+1<<endl;
		}
		else{
			cout<<(n*n)/4-1<<' '<<(n*n)/4+1<<endl;
		}
	}

	// for(int i=1;i<100;i++){
	// 	cout<<((i+2)*(i+2)) - (i*i)<<endl;
	// }
	// 任意一个数，如果它的平方是奇数，那么就可以表示成一个三角
	// n m m+1
	// n*n = m+1+m
	// 除了一意外都可以

	// 任意一个数，如果它是偶数
	// 那么 一定可以吗？
	// 除了2以外的都可以
	// n*n = (m+2+m)*2
	// (m+2+m)(2) = n*n
	// n*n/2 == 2m+2

	return 0;
}
