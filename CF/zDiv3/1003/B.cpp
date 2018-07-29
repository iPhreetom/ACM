#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,a,b;
string ans = "";

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>x;
	swap(a,b);

	// for(int i=0;i<a;i++){
	// 	if(b){
	// 		b--;
	// 		ans.push_back('0');
	// 	}
	// 	ans.push_back('1');
	// }
	//
	// while(b){
	// 	ans.push_back('0');
	// }
	//
	// if(x < min(a,b)*2){
	// 	if(a =< b){
	//
	// 	}
	// }

	if(a >= b){
		ans.push_back('1');
		a--;

		bool one = 0;
		for(int i=0;i<x;i++){
			if(one){
				ans.push_back('1');
				one = !one;
				a--;
			}
			else{
				ans.push_back('0');
				one = !one;
				b--;
			}
		}

		while(b){
			b--;
			ans.insert(ans.begin()+1,'0');
		}

		while(a){
			a--;
			ans.insert(ans.begin(),'1');
		}
	}
	else{
		ans.push_back('0');
		b--;

		bool one = 1;
		for(int i=0;i<x;i++){
			if(one){
				ans.push_back('1');
				one = !one;
				a--;
			}
			else{
				ans.push_back('0');
				one = !one;
				b--;
			}
		}
		while(a){
			a--;
			ans.insert(ans.begin()+1,'1');
		}

		while(b){
			b--;
			ans.insert(ans.begin(),'0');
		}

	}
	cout<<ans<<endl;
	return 0;
}
