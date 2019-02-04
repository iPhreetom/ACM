// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string s;
int index = 1;
int lastindex = 0;

inline void ask(int x,int y) {
		cout << "? " << x << ' ' << y <<endl;
}

void tryfind(int l, int r) {
	while(1){
		ask(l+lastindex , min(l+index, r));
		cin >> s;
		if(s == "mistake" || s == "e"){
			return ;
		}
		if(s == "x") {
			if(min(l+index, r) - (lastindex+l) <= 1){
				cout<<"! "<<min(l+index, r)<<endl;
				return ;
			}
			else{
				// int ll = lastlastindex;
				int lt = lastindex;
				int in = index;
				lastindex = 0;
				index = 1;
				tryfind(l+lt,min(l+in,r));
				return ;
			}
		}
		else {
			// lastlastindex = lastindex;
			lastindex = index;
			index = 2*index;
			// if(index == 1)index = 2;
		}
	}
}
// 536870860


signed main(){
	while(1) {
		cin >> s;
		if(s == "mistake"  || s == "e")break;
		if(s == "start") {
			index = 1;
			lastindex = 0;
			tryfind(1-1, 1000000000);
			if(s == "mistake")break;
			continue;
		}
		else if(s == "end") {
			break;
		}
	}

	return 0;
}
