#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> mp[212345];

int father[212345];
int n,m,q;

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
	if(fathera == fatherb)return ;

	father[fathera] = father[fatherb];
}




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	cin>>n>>m>>q;
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		mp[x].push_back(y);
	}
	for(int i=0;i<212345;i++){
		if(mp[i].size() == 0)continue;
		sort(mp[i].begin(),mp[i].end());
		for(int j=0;j<mp[i].size();j++){
			unit(mp[i][j],mp[i][0]);
		}
	}


	return 0;
}
