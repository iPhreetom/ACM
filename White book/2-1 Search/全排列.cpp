#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[4] = {1,2,4,4};

	// 使用全排列函数生成所有排列情况
	while(next_permutation(a,a+4)){
		for(int i=0;i<4;i++){
			cout<<a[i]<<' ';
		}cout<<endl;
	}


	return 0;
}
