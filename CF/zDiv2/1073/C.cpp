// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
string s;
int x,y;
int nx,ny;

void move(char &ch){
	if(ch == 'R'){
		nx++;
	}
	else if(ch == 'L'){
		nx--;
	}
	else if(ch == 'D'){
		ny--;
	}
	else if(ch ==  'U'){
		ny++;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n;
	cin>>s;
	cin>>x>>y;

	// end 1
	if( abs(x) + abs(y)  > n){
		cout<<-1<<endl;
		return 0;
	}

	// end 2
	if( (n - (abs(x) + abs(y)) )  % 2 == 1){
		cout<<-1<<endl;
		return 0;
	}

	// get now x,y
	for (int i=0; i<s.size(); i++){
		move(s[i]);
	}

	// end 3
	if(nx == x && ny == y){
		cout<<0<<endl;
		return 0;
	}

	int l = 0;
	int r = s.size()-1;
	nx = 0;
	ny = 0;
	bool left = 0;
	int cnt = 0;
	while(l < r){
		if(left){
			int tx = nx;
			int ty = ny;
			move(s[l]);
			int dif = abs(nx - x)+abs(ny - y);

			left = !left;
			if(dif <= r-l){
				l++;
				cnt = 0;
			}
			else{
				nx = tx;
				ny = ty;
				cnt++;
				if(cnt == 2){
					break;
				}
			}
		}
		else{
			int tx = nx;
			int ty = ny;
			move(s[r]);
			int dif = abs(nx - x)+abs(ny - y);

			left = !left;
			if(dif <= r-l){
				r--;
				cnt = 0;
			}
			else{
				nx = tx;
				ny = ty;
				cnt++;
				if(cnt == 2){
					break;
				}
			}
		}
	}
	cout<<r-l+1<<endl;



	return 0;
}
