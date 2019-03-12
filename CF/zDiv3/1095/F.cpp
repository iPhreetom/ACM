#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n, m;
vector<pair<int,int>> v;
vector<int> a(212345, 0);
typedef pair<int,pair<int,int>> pii;
priority_queue<pii,vector<pii>,greater<pii>> que;
int father[212345];

void init(int n){
	for (int i=0; i<=n; i++){
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


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	init(n);

	for (int i=1; i<=n; i++){
		cin >> a[i];
		v.push_back(make_pair(a[i], i));
	}
	sort(v.begin(),v.end());

	for (int i=1; i<=m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		que.push(make_pair(w,make_pair(u,v)));
	}

	int cnt = 1;
	int index = 1;
	int sum = 0;
	while(cnt < n) {
		cnt++;

		while(!que.empty()) {
			int u = que.top().second.first;
			int v = que.top().second.second;
			if(same(u,v)) {
				que.pop();
			}
			else break;
		}
		int mntop;
		if(!que.empty()) mntop = que.top().first;
		else mntop = 1e18;

		while (index < n) {
			if(same(v[0].second,v[index].second)){
				index++;
			}
			else break;
			// cout<<"index = "<<index<<endl;
		}
		int mncost = v[0].first + v[index].first;


		if(mncost <= mntop) {
			unite(v[0].second,v[index].second);
			// cout<<"v[0].second = "<<v[0].second<<endl;
			// cout<<"v[index].second = "<<v[index].second<<endl;
			// cout<<"mncost = "<<mncost<<endl;
			sum += mncost;
		}
		else {
			int u = que.top().second.first;
			int v = que.top().second.second;
			// cout<<"u = "<<u<<endl;
			// cout<<"v = "<<v<<endl;
			unite(u,v);
			sum += mntop;
			// cout<<"mntop = "<<mntop<<endl;
		}
	}
	cout << sum << endl;
	return 0;
}
