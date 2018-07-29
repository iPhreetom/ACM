// CF 975C arrows and warrior
// 二分法(stl lower_bound) + 多次前缀数组
// 知识点：
// 	通过使用Lower_bound 和 upper_bound快速的在数组或者（stl set）中找值
#include<bits/stdc++.h>
using namespace std;

long long n,q;
long long a[212345],b[212345],s[212345];
long long res;
long long arrow_sum=0,fall_sum=0;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int test[10];
	test[0] = 0;
	for(int i=1;i<10;i++){
		test[i] = i*10;
	}
	cout<<upper_bound(test,test+10,0)-(test)<<endl;
	// 0 10 20
	// 2 ?
	cout<<lower_bound(test,test+10,0)-(test+1)<<endl;
	// 3!

	// cout<<upper_bound(test+1,test+10,5)-test<<endl;
	// cout<<upper_bound(test+1,test+10,9)-test<<endl;
	// cout<<upper_bound(test+1,test+10,8)-test<<endl;
	// cout<<upper_bound(test+1,test+10,19)-test<<endl;
	// cout<<upper_bound(test+1,test+10,0)-test<<endl;
	// cout<<lower_bound(test+1,test+10,4)-test<<endl;



	// upper_bound（i） 返回的是键值为i的元素可以插入的最后一个位置（上界）
	// lowe_bound（i） 返回的是键值为i的元素可以插入的位置的第一个位置（下界）。
	return 0;

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i] = a[i]+b[i-1];
	}
	// cout<<"---"<<endl;
	// for(int i=1;i<=n;i++){
	// 	cout<<b[i]<<' ';
	// }
	// cout<<endl<<"----"<<endl;
	for(int i=1;i<=q;i++){
		cin>>s[i];
		arrow_sum += s[i];
		long long pos = upper_bound(b+1,b+n+1,arrow_sum)-b;
		// cout<<endl<<pos<<"----"<<arrow_sum<<endl;
		if(pos == n+1){
			cout<< n <<endl;
			arrow_sum = 0;
			// fall_sum = 0；
		}
		else{
			cout<<n - pos + 1<<endl;
			// fall_sum
		}
	}
	return 0;
}
