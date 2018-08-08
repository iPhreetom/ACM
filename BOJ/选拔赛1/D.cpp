#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


/*
3 0
bool conf[4];


*/
bool conf[4];

int a = 0;

void work(int ret){
	int ten,one;
	one = ret % 10;
	ret /= 10;
	ten = ret % 10;

	if(ten == 3){
		
	}
	else if(ten == 2){

	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(a != 40){
		work(a);

		fflush(stdout);
		cin>>a;
	}

	return 0;
}
