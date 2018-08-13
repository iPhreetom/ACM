// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,h,a,b,k;
	cin>>n>>h>>a>>b>>k;
	for (int i=0; i<k; i++){
		int ta,fa,tb,fb;
		cin>>ta>>fa>>tb>>fb;
		if(ta == tb){
			cout<<abs(fa-fb);
		}
		else if(fa > b){
			cout<<abs(ta-tb) + (fa-b) + abs(b-fb);
		}
		else if(fa < a){
			cout<<abs(ta-tb) + (a - fa)+abs(a-fb);
		}
		else{
			cout<<abs(ta-tb) + abs(fa-fb);
		}
		cout<<'\n';
	}
	return 0;
}
