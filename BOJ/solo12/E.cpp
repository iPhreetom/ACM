
#include<bits/stdc++.h>
using namespace std;


struct cube{
	int x,y,num;
	int up=0;

	cube(int x,int y,int num):x(x),y(y),num(num);
	bool operator<(const cube &a) const{
		return this->num < a.num;
	}

};

bool cmp(cube &a,cube &b){

}

int n,x,y;
vector<cube> a;
priority_queue<cube,cmp> que;


int main(){
	ios::sync_with_stdio(false);cin.tie(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a.push_back(cube(x,y,i));
	}
	for(int i=0;i<n;i++){
		que
	}
	return 0;
}
