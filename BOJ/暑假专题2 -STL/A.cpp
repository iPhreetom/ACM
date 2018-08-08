#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int father[2123];
int n,m;

void init(){
	for(int i=0;i<=n;i++){
		father[i] = i;
	}
}

int findfather(int a){
	int root = a;
	while(father[root] != root){
		root = father[root];
	}

	while(a != root){
		int temp = father[a];
		father[a] = root;
		a = temp;
	}

	return a;
}

void unit(int a,int b){
	int fathera = findfather(a);
	int fatherb = findfather(b);

	father[fathera] = father[fatherb];
}



signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n>>m){
		init();
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			unit(u,v);
		}
		set<int> s;
		for(int i=1;i<=n;i++){
			s.insert(findfather(i));
		}
		cout<<s.size()-1<<endl;
	}

	return 0;
}
