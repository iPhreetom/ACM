#include<bits/stdc++.h>
// #define int long long
// #define double long double
using namespace std;


int n;
int sx,sy;
int sum = 0;

int mxy[2123456];
int mny[2123456];
int up = -1e9,down = 1e9,lt = 1e9,rt = -1e9;

void dfs (int tx, int ty,int d) {
	if(d == 1) {
		if(mxy[tx+1] == -1e9) { // 没点
			tx++;
			ty++;
			sum++;
		}
		else{
			if(mxy[tx+1] > ty) { // 下一行，在我上面
				sum += (mxy[tx+1]-ty);
				ty = mxy[tx+1];
			}
			else{ // 小于或者等于我
				sum ++;
				tx++;
				ty++;
			}
		}
		if(ty > up)d = 2;
	}
	else if(d == 2) {
		if(mxy[tx+1] == -1e9) { // 没点
			tx++;
			ty--;
			sum++;
		}
		else{
			if(mxy[tx+1] > ty) { // 下一行，在我上面
				sum += (mxy[tx+1]-ty);
				ty = mxy[tx+1];
			}
			else{ // 小于或者等于我
				sum ++;
				tx++;
				ty++;
			}
		}
	}
	else if(d == 3) {

	}
	else if(d == 4) {

	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	for (int i=0; i<2123456; i++){
	    mxy[i] = -1e9;
		mny[i] = 1e9;
	}

	cin >> n;
	for (int i=1; i<=n; i++){
	    int tx,ty;
		cin>>tx>>ty;

		tx += 1e6+1;
		ty += 1e6+1;

		mxy[tx] = max(mxy[tx],ty);
		mny[tx] = min(mny[tx],ty);
		up = max(up,ty);
		down = min(down,ty);
		lt = min(lt,tx);
		rt = min(rt,tx);

		if(tx <= sx) {
			sx = ZSaeftx-1;
			sy = ty;
		}
	}

	// 1 2 3 4
	dfs(sx, sy, 1);
	return 0;
}
