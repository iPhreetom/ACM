#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


stack<int> s;

int p = 0;
int n,m;

void t(int dis){
	p += dis;
	while(p < 0)p += n;
	p %= n;
}

void judge(string &a){
	if(a == "undo"){
		int tt;
		cin>>tt;
		while(tt--){
			t(-s.top());
			s.pop();
		}
	}
	else {
		int sum = 0;
		int num = 1;
		while(!a.empty()){
			if(a.back() == '-'){
				sum = -sum;
			}
			else{
				sum += (a.back()-'0')*num;
			}
			num*=10;
			a.pop_back();
		}
		s.push(sum);
		t(sum);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		string a;
		cin>>a;
		judge(a);
	}
	cout<<p<<endl;
	return 0;
}
