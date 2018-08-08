#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


int n,m;

int father[212345];
int add[212345];
int num[212345];
int index1 = 100005;

int findfather(int a){
	int root = a;
	while(root != father[root]){
		root = father[root];
	}
	while(a != father[a]){
		int t = father[a];
		father[a] = root;
		a = t;
	}
	return root;
}

void unite(int a,int b){
	int x = findfather(a);
	int y = findfather(b);
	if(x == y)return ;

	add[y] += add[x];
	num[y] += num[x];

	father[x] = y;
}

void move(int a,int b){
	int x = findfather(a);
	int y = findfather(b);
	if(x == y)return ;

	add[y] += a;
	num[y] += 1;

	add[x] -= a;
	num[x] -= 1;

	father[a] = y;
}

void sum(int a){
	int root = findfather(a);
	cout<<num[root]<<' '<<add[root]<<endl;
}

void init(){
	for(int i=1;i<212345;i++){
		father[i] = i;
		add[i] = i;
		num[i]= 1;
	}

	index1 = 100005;
	for(int i=index1;i<212345;i++){
		add[i] = 0;
		num[i] = 0;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	while(cin>>n>>m){
		init();
		for(int i=0;i<m;i++){
			int t;
			cin>>t;
			if(t == 1){
				int a,b;
				cin>>a>>b;
				if(father[a] == a && father[b] == b){
					unite(b,index1);
					unite(a,index1);
					index1++;
				}
				else{
					if(father[a] == a){
						unite(a,b);
					}
					else{
						unite(b,a);
					}
				}
			}
			if(t == 2){
				int a,b;
				cin>>a>>b;
				if(father[b] == b){
					unite(b,index1);
					index1++;
				}
				move(a,b);
			}
			if(t == 3){
				int a;
				cin>>a;
				sum(a);
			}
		}
	}
	return 0;
}
