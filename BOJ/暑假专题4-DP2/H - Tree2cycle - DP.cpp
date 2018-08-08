#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
double r;
double x,y,r2;
double pi = 3.141592653589793238462643383279;
struct node{
	double x;
	double y;
	double r;
};
vector<node> arr;

double getlen(int index){

}

double dis(int x,int y){
	return sqrt(x*x+y*y);
}

void solve(){
	double len = 2*pi*r;
	for(int i=0;i<arr.size();i++){
		double k1 = y/x;
		double k2 = 1/k1;
		double a = 
		double x1 = a*c+a*sqrt(c*c)
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		arr.clear();
		cin>>n;cin>>r;
		for (int i=0; i<n; i++){
		    cin>>x>>y>>r2;
			if(dis(x,y)+r2 < r){
				continue;
			}
			else{
				arr.push_back(node{x,y,r2});
			}
		}
		solve();
	}
	return 0;
}
