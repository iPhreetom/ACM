// CF 989A spring is coming
// 	总结：
// 		使用size()的时候，有位注意，它是一个无符号类型，如果减去一个比它大的数字（严格比它大），会得到一个非常大的数
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;


int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;

	// cout<<a.size()-2<<endl;
	// if(a.size()<=2){
	// 	cout<<"No"<<endl;
	// 	return 0;
	// }
	char b[100];
	auto al = strlen(b);
	cout<<al<<endl;
	cout<<al-10<<endl;
	//

	for(int i=0;i<ll(a.size())-2;i++){
		if(a[i]!='.' && a[i+1]!='.' && a[i+2]!='.'){
			if(a[i]!=a[i+1] && a[i]!=a[i+2] && a[i+1]!=a[i+2]){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	// if(a.size()!=6)cout<<"Yes"<<endl;

	cout<<"No"<<endl;
	return 0;
}
