// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

vector<pair<int,int> > mp[212345];

int val[212345];
int cnt[212345];
int fa[212345];
double avg[212345];

int getval(int u, int f) {
	int sum = 0;
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i].first;
		if (v != f) {
			sum += mp[u][i].second;
			sum += getval(v, u);
		}
	}
	fa[u] = f;
	val[u] = sum;
	return sum;
}

int getcnt(int u, int f) {
	int num = 0;
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i].first;
		if (v != f) {
			num += getcnt(v,u);
		}
	}
	cnt[u] = num;
	return num+1;
}

double getmin(int u,int f) {
	vector<pair<double,pair<int,int>>> judge;
	for (int i=0; i<mp[u].size(); i++){
		int v = mp[u][i].first;
		if (v != f) {
			judge.push_back({(double)(val[v]+mp[u][i].second)*(double)(cnt[u]-(cnt[v]+1)),make_pair(v,i)});
			getmin(v,u);
		}
 	}
	sort(judge.begin(),judge.end());
	int res = cnt[u];
	double ret = 0;
	for (int i=0; i<judge.size(); i++){
		int v = judge[i].second.first;
		int j = judge[i].second.second;
		res -= (cnt[v]+1);
		ret += avg[v] + (double)mp[u][j].second*(cnt[v]+1) + ((double)val[v]*2.0 + mp[u][j].second*2)*(res);
	}
	avg[u] = ret;
	return ret;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n-1; i++){
		int a,b,t;
		cin >> a >> b >> t;
		mp[a].push_back(make_pair(b,t));
		mp[b].push_back(make_pair(a,t));
	}
	getval(1,0);
	getcnt(1,0);
	cout << fixed << setprecision(9) << getmin(1,0)/(n-1) << endl;
	return 0;
}
