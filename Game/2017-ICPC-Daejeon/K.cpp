	#include<bits/stdc++.h>
	#define int long long
	#define double long double
	#define endl '\n'
	using namespace std;

	int mxup = 0;
	int mxdown = 0;
	int mxleft = 0;
	int mxright = 0;
	int x,y;

	void turn(int &way,int f){
		if(way == 1){
			if(f == 1){
				way = 2;
			}
			if(f == -1){
				way = 3;
			}
		}

		else if(way == 2){
			if(f == 1){
				way = 4;
			}
			if(f == -1){
				way = 1;
			}
		}

		else if(way == 3){
			if(f == 1){
				way = 1;
			}
			if(f == -1){
				way = 4;
			}
		}

		else if(way == 4){
			if(f == 1){
				way = 3;
			}
			if(f == -1){
				way = 2;
			}
		}
	}

	void change(int way,int l){
		if(way == 1){
			mxup++;
			cout<<abs(y-mxup)<<' ';
			y = mxup;
		}
		if(way == 2){
			mxleft--;
			cout<<abs(x-mxleft)<<' ';
			x = mxleft;
		}
		if(way == 3){
			mxright++;
			cout<<abs(x-mxright)<<' ';
			x = mxright;
		}
		if(way == 4){
			mxdown--;
			cout<<abs(y-mxdown)<<' ';
			y = mxdown;
		}
	}

	signed main(){
		ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
		int n;
		cin>>n;
		int way = 1;
		// 1 UP
		// 2 left
		// 3 right
		// 4 DOWN

		// mxup
		// mxdown
		// mxleft
		// mxright


		for (int i=0; i<n; i++){
			int l,f;
			cin>>l>>f;
			change(way,l);
			turn(way,f);
		}

		return 0;
	}
