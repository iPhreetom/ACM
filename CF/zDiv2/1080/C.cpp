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
void add_up(){
	if(y[2] > y[4]){
		int height = y[2] - y[4];
		int width = x[2] - x[1];
		width++;
		int area = width*height;
		int corner = get_color(x[1], y[2]);
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
}
void add_down(){
	if(y[1] < y[3]){
		int height = y[3] - y[1];
		int width = x[2] - x[1];
		width++;
		int area = width*height;
		int corner = get_color(x[1], y[1]);
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
}
void add_left(){
	if(x[1] < x[3]){
		int height = y[2] - y[1];
		int width = x[3] - x[1];
		height++;
		int area = width*height;
		int corner = get_color(x[1], y[1]);
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
}
void add_right(){
	if(x[2] > x[4]){
		int height = y[2] - y[1];
		int width = x[2] - x[4];
		height++;
		int area = width*height;
		int corner = get_color(x[2], y[2]);
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
}
void sub_up_right(){
	if(x[2] > x[4] && y[2] > ){
		int height = y[2] - y[1];
		int width = x[2] - x[4];
		height++;
		int area = width*height;
		int corner = get_color(x[2], y[2]);
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
}

void try_add_white(){
	add_up();
	add_down();
	add_left();
	add_right();

	sub_up_right();
	sub_up_left();
	sub_down_right();
	sub_down_left();
}
void solve(){
	cin >> n >> m;
	num_w = (n*m+1)/2;
	num_b = (n*m)/2;
	cin >> x[1] >> y[1] >> x[2] >> y[2];
	cin >> x[3] >> y[3] >> x[4] >> y[4];
	add_all_black();
	try_add_white();
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
int lx = max(x[1],x[3]);
int ly = max(y[1],y[3]);
int rx = min(x[2],x[4]);
int ry = min(y[2],y[4]);
