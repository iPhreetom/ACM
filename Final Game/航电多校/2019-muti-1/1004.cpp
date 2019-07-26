// fyt
#include<bits/stdc++.h>
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxn = 1e5 + 5;
int father[maxn];
bool vis[maxn];
long long dis[maxn];
void init(int n){
	for (int i=0; i<=n+3; i++){
	    father[i]=i;
		vis[i] = 0;
		dis[i] = 0;
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
	int n;
	while (cin >> n) {
		vector<double> l(n+1);
		vector<double> s(n+1);
		vector<double> v(n+1);
		for (int i=0; i<=n; i++){
			int tp ; cin >> tp;
			l[i] = tp;
		}
		for (int i=0; i<=n; i++){
			int tp; cin >> tp;
			s[i] = tp;
			// cin >> s[i];
		}
		for (int i=0; i<=n; i++){
			int tp; cin >> tp;
			v[i] = tp;
			// cin >> v[i];
		}

		// get min
		int mn = 2e9;
		int index = 0;
		for (int i=0; i<=n; i++){
			if (mn > v[i]) {
				index = i;
				mn = v[i];
			}
		}
		// delte
		int num = index+1;
		while(l.size() > num) {
			l.pop_back();
			s.pop_back();
			v.pop_back();
		}


		cout << fixed << setprecision(12);
		// judge
		if (l.size() == 1) {
			cout << (double)s[0]/(double)v[0] << endl;
			continue;
		}

		priority_queue<pair<double,int>> que;

		n = l.size()-1;
		init(n);
		for (int i=1; i<=n; i++){
			double sp = (s[i-1]-(s[i]+l[i]))/(v[i]-v[i-1]);
			que.push(make_pair(sp,i));
		}

		double last = 0;
		double now = 0;
		bool f = 0;
		while(!que.empty()) {
			double mn = que.top().first;
			int index = que.top().second;
			que.pop();

			// muti?
			if (vis[index]) continue;
			// judge 0
			int zero = findfather(0);
			double pass = now*v[zero] + dis[0];
			if (pass >= s[0]) {
				int lastpass = last*v[zero] + dis[0];
				cout << lastpass + (s[0]-lastpass)/v[zero]/2 << endl;
				f = 1;
				break;
			}

			// update speed
			int left = findfather(index-1);
			int right = findfather(index);
			v[index-1] = v[index];

			// update length
			l[right] += l[left];

			// update sp
			double leftpoint = s[left]-now*v[left];
			double rightpoint = s[right]-now*v[right] + l[right];
			double dist = rightpoint-leftpoint;
			double newsp = dist/(v[left]-v[right]);
			dis[left] += now*(v[left]-v[right]);

			if (index != 1) que.push(make_pair(newsp,index-1));
			vis[index] = 1;

			unite(left,right);
		}

		// output
		if (!f) {
			int zero = findfather(0);
			double pass = now*v[zero] + dis[0];
			cout << pass + (s[0]-pass)/v[zero]/2 << endl;
		}
	}
	return 0;
}
