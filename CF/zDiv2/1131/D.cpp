// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn= 1e5+7;

int T,n,m,u,v,num;
int InDeg[maxn];
vector<int>vec[maxn];
queue<int>q;

int father[105];

void init(){
	for (int i=0; i<105; i++){
	    father[i]=i;
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

	father[x] = y;
	// ps: some point's father[s..] is't it's root
}


bool topsort(){
        while(!q.empty())q.pop();
        num=0;
        for(int i=1;i<=n;i++)if(!InDeg[i])q.push(i);
        while(!q.empty()){
        	int now=q.front();q.pop();num++;
        	for(int i=0;i<vec[now].size();i++){
        		if(--InDeg[vec[now][i]]==0)q.push(vec[now][i]);
			}
		}
		if(num==n)return true;
		else return false;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		string s;
		cin >> s;
		for (int j=0; j<s.size(); j++){
			if(s[i] == '>') {

			}
			else if(s[i] == '<') {

			}
			else {
				//
				
			}
		}
	}
	return 0;
}
