// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

queue<int> que[212345];
int father[212345];

void init(){
	for (int i=0; i<212345; i++){
	    father[i]=i;
		que[i].push(i);
	}
}

int findfather(int x){
	int root=x;
	while(father[root] != root){
		root = father[root];
	}

	while(father[x] != x){
		int t = father[x];
		father[x] = root;
		x = t;
	}
	return root;
}

bool same(int l,int r){
	int x = findfather(l);
	int y = findfather(r);
	return x == y;
}


void unite(int l,int r){
	int x = findfather(l);
	int y = findfather(r);
	if(x == y)return ;


	if(que[x].size() <= que[y].size()) father[x] = y;
	else father[y] = x;
	// ps: some point's father[s..] is't it's root
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	init();

	for (int i=1; i<=n-1; i++){
		int x,y;
		cin >> x >> y;
		x = findfather(x);
		y = findfather(y);
		unite(x, y);

		-}
	}

	for (int i=1; i<=n; i++){
		if(!que[i].empty()) {
			while(!que[i].empty()) {
				cout << que[i].front() << ' ';
				que[i].pop();
			}
			cout << endl;
			return 0;
		}
	}
	return 0;
}
