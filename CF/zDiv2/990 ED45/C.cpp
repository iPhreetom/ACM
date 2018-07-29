
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

long long l,r,f,same;

// set<string> sa;
// set<long long> num;
// ll mod = 1e5+3;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	string a;
	while(n--){
		cin>>a;
		bool ok=1;

		if(a.size()>=2){
			if(a[0] == ')' && a[a.size()-1] == '(')continue;

			int lt=0,rt=0;
			if(a[0] == ')'){
				for(int i=1;i<a.size();i++){
					if(a[i] == '(')lt++;
					else rt++;
					if(rt > lt){
						goto END ;
					}
				}
				if(rt == lt)r++;
			}
			else{
				if(a[a.size()-1] == '('){
					for(int i=0;i<a.size()-1;i++){
						if(a[i] == '(')lt++;
						else rt++;
						if(rt > lt){
							goto END ;
						}
					}
					if(rt == lt)l++;
				}
				else{//f
					for(int i=0;i<a.size();i++){
						if(a[i] == '(')lt++;
						else rt++;
						if(rt > lt){
							goto END ;
						}
					}
					if(rt == lt){
						f++;
					}
				}
			}

		}
		else{
			if(a[0] == '(')l++;
			if(a[0] == ')')r++;
		}
		END: ;
	}
	// cout<<l<<' '<<r<<endl;
	cout<<l*r+f*f<<endl;


	return 0;
}
