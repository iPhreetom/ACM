// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct node{
	int a,b;
	bitset<20> state;

	node(){}
	node(int a,int b){
		this->a = a;
		this->b = b;
	}
};

vector<node> arr;
bool vis[1<<20];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int a,b,s;
		cin>>a>>b>>s;
		arr.push_back(node(a,b));
		auto &t = arr.back();
		for (int i=0; i<s; i++){
			int q;
			cin>>q;
			arr[i].state[q-1] = 1;
		}
	}
	vis[0]=1;
	for(int i=1;i<1<<20;i++){
		
	}

	return 0;
}
