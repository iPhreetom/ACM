// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

vector<int> lis(16);

void init(){
	for (int i=1; i<=15; i++){
		lis[i] = 1;
		for (int j=1; j<=i; j++){
			lis[i]*=i;
		}
		if(lis[i]!=pow(i,i)){
			cout<<"lis[i] = "<<lis[i]<<endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	init();
	// cout<<lis.size()<<endl;
	// for (int i=0; i<lis.size(); i++){
	//     cout<<lis[i]<<' ';
	// }cout<<endl;
	int n;
	while(cin>>n){
		int num=0;
		for (int i=1; i<=15; i++){
			if(lis[i] <= n)num++;
			else break;
		}
		cout<<num<<endl;
	}
	return 0;
}
