// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n, m, x[5], y[5],num_w,num_b;
int get_color(int x,int y){
	if(x%2 == y%2){
		return 1;//w
	}
	else{
		return 0;// b
	}
}
void add_all_black(){
	int width = x[4]-x[3];
	int height = y[4]-y[3];
	width++;
	height++;
	int area = width*height;
	int corner = get_color(x[3],y[3]);
	if(width %2 == 0 || height%2 == 0){
		num_b += area/2;
		num_w -= area/2;
	}
	else{
		if(corner){
			// white
			num_b += (area+1)/2;
			num_w -= (area+1)/2;
		}
		else{
			num_b += area/2;
			num_w -= area/2;
		}
	}
}
void add_all_white(){
	int width = x[2]-x[1];
	int height = y[2]-y[1];
	width++;
	height++;
	int area = width*height;
	int corner = get_color(x[1],y[1]);
	if(width %2 == 0 || height%2 == 0){
		num_w += area/2;
		num_b -= area/2;
	}
	else{
		if(corner){
			// white
			num_w += area/2;
			num_b -= area/2;
		}
		else{
			num_w += (area+1)/2;
			num_b -= (area+1)/2;
		}
	}
}
void sub_white(){
	if(x[1] > x[4] || x[2] < x[3] || y[1] > y[4] || y[2] < y[3]){
		return ;
	}
	int lx = max(x[1],x[3]);
	int ly = max(y[1],y[3]);
	int rx = min(x[2],x[4]);
	int ry = min(y[2],y[4]);
	int corner = get_color(lx, ly);
	int width = abs(rx-lx);
	int height = abs(ry-ly);
	width++;
	height++;
	// cout<<"width = "<<width<<endl;
	// cout<<"height = "<<height<<endl;
	// cout<<"corner = "<<corner<<endl;
	// cout<<"lx = "<<lx<<endl;
	// cout<<"ly = "<<ly<<endl;
	int area = width*height;

	if(width %2 == 0 || height%2 == 0){
		num_b += area/2;
		num_w -= area/2;
	}
	else{
		if(corner){
			// white
			num_b += area/2;
			num_w -= area/2;
		}
		else{
			num_b += (area+1)/2;
			num_w -= (area+1)/2;
		}
	}
}
void solve(){
	cin >> n >> m;
	num_w = (n*m+1)/2;
	num_b = (n*m)/2;
	cin >> x[1] >> y[1] >> x[2] >> y[2];
	cin >> x[3] >> y[3] >> x[4] >> y[4];
	add_all_white();
	add_all_black();
	sub_white();
	cout<<num_w<<' '<<num_b<<endl;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int test;
	cin>>test;
	while(test--){
		solve();
	}
	return 0;
}
