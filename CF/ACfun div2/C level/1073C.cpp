//1073C
// 二分答案，求最小值，小于最小值的都不成立，大于最小值的都成立
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int n;
string s;
int x,y;
int nx,ny;
int prex[212345];
int prey[212345];

void move(char ch){
	if(ch == 'U'){
		ny ++;
	}
	if(ch == 'D'){
		ny--;
	}
	if(ch == 'R'){
		nx++;
	}
	if(ch == 'L'){
		nx--;
	}
}

void rmove(char ch){
	if(ch == 'U'){
		ny--;
	}
	if(ch == 'D'){
		ny++;
	}
	if(ch == 'R'){
		nx--;
	}
	if(ch == 'L'){
		nx++;
	}
}

bool check(int mid){
	nx = prex[n]-prex[mid];
	ny = prey[n]-prey[mid];
	int dif = abs(nx-x)+abs(ny-y);
	if(mid >= dif)return 1;

	// cout<<"mid = "<<mid<<endl;
	for(int i=0;i<n-mid;i++){
		move(s[i]);
		rmove(s[i+mid]);
		dif = dif = abs(nx-x)+abs(ny-y);
		if(mid >= dif)return 1;
	}

	return 0;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>s;
	cin>>x>>y;

	nx = 0,ny = 0;
	for(int i=0;i<n;i++){
		move(s[i]);
		prex[i+1] = nx;
		prey[i+1] = ny;
	}

	// judge 1
	if(n < abs(x)+abs(y)){
		cout<<-1<<endl;
		return 0;
	}
	// judge 2
	int dif = abs(nx-x)+abs(ny-y);
	int tot = abs(x)+abs(y);
	if(abs(tot-n) % 2 == 1){
		cout<<-1<<endl;
		return 0;
	}

	int l = 0 , r = n+1;
	while(l+1 < r){
		int mid = l+(r-l)/2;
		if(check(mid))r = mid;
		else l = mid;
	}
	if(check(l))cout<<l<<endl;
	else cout<<r<<endl;

	return 0;
}
