
#include<bits/stdc++.h>
using namespace std;

bool book[1123456];

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	// 0 0 0 0 0
	// 0 1 0 0 0
	// 0 1 1 1 0

	// 0 1 1 1 1
	// 如果出现了重复，可能性就double，如果可能性被覆盖，
	// 1 1 0 1 1
	// 1 1 1 1 0
	int n,m,tp;
	for(int i=0;i<m;i++){
		cin>>tp;
		if(book[tp]){
			
		}
		else{
			book[tp]=1;
		}
	}
	return 0;
}
