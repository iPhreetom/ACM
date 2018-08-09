// c++ 处理空行分割的方法：
	// getline(cin,s)
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	// cin>>noskipws;
	string a;
	while(1){
		// cin.getline(a);
		getline(cin,a);
		cout<<a.size()<<endl;
	}
	return 0;
}
