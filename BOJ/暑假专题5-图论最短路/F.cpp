#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>

#define int long long
#define double long double
using namespace std;


// 模板，模板，记下来
struct node{
	double len;
	int l;
	int r;
	bool operator < (const node &a) const{
        //按len由小到大排列，如果要由大到小排列，使用“>”即可；
        return a.len < len;
    }

	node(double len ,int l ,int r){
		this->len = len;
		this->l = l;
		this->r = r;
	}
};
priority_queue<node> que;
vector<pair<double,double>> arr;
int n;
int fa[105];



void init(){
	for (int i=0; i<105; i++){
	    fa[i]=i;
	}
}

int findfa(int x){
	int root=x;
	while(fa[root] != root){
		root = fa[root];
	}

	while(fa[x] != x){
		int t = fa[x];
		fa[x] = root;
		x = t;
	}
	return root;
}

bool same(int l,int r){
	int x = findfa(l);
	int y = findfa(r);
	return x == y;
}


void unite(int l,int r){
	int x = findfa(l);
	int y = findfa(r);
	if(x == y)return ;

	fa[x] = y;
	// ps: some point's fa[s..] is't it's root
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0; i<n; i++){
	    double x,y;
		cin>>x>>y;
		arr.push_back(make_pair(x,y));
	}
	for (int i=0; i<arr.size(); i++){
		for (int j=0; j<arr.size(); j++){
		    if(i!=j){
				double len = sqrt((arr[i].first-arr[j].first)*(arr[i].first-arr[j].first) + (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second));
				que.push(node(len,i+1,j+1));
			}
		}
	}

	double ans = 0;
	init();
	while(!que.empty()){
		node p = que.top();
		que.pop();
		if(!same(p.l,p.r)){
			unite(p.l,p.r);
			ans += p.len;
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<endl;

	return 0;
}
