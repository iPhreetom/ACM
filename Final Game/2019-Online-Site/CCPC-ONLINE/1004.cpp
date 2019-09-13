// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int ans[51234];

typedef pair<pair<int,pair<int,int>>,pair<int,int>> pii; // w id len from to
vector<pair<int,pair<int,int>>> mp[51234];
vector<pair<int,pair<int,int>>> rmp[51234];
const int maxn = 5e4+20;

struct node {
	int val,id,from,to,len;
};
bool operator < (const node &leftObj, const node &rightObj) {
	return leftObj.val < rightObj.val;
}

const int base = 233333;
const int mod = 1e9+7;
int kq[51234];
void getkq() {
	kq[0] = 1;
	for (int i=1; i<=51233; i++){
		kq[i] = kq[i-1]*base%mod;
	}
}

void init(int n) {
	for (int i=0; i<=n; i++){
		mp[i].clear();
		rmp[i].clear();
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	getkq();
	int T;
	cin >> T;
	while(T--){
		priority_queue<pii,vector<pii>,greater<pii>> que;
		unordered_set<int> st;
		// map<int,int> sk;
		int n, m, q;
		cin >> n >> m >> q;
		init(n);
		while(m--){
			int u,v,w;
			cin >> u >> v >> w;
			mp[u].push_back(make_pair(w,make_pair(v,m+5)));
			rmp[v].push_back(make_pair(w,make_pair(u,m+5)));
			que.push({{w,{m+5,1}},{u,v}});
		}

		for (int i=1; i<=n; i++){
			sort(mp[i].begin(),mp[i].end());
			sort(rmp[i].begin(),rmp[i].end());
		}

		// mp[from] w, to, id,
		// que w,id,len,from,to
		int cnt = 1;
		while(cnt <= maxn && !que.empty() && st.size() < 1e5) {
			int val = que.top().first.first;
			int id = que.top().first.second.first;
			int len = que.top().first.second.second;
			int from = que.top().second.first;
			int to = que.top().second.second;
			que.pop();

			ans[cnt] = val;
			cnt++;
			int mn = 1e18;
			// if (!que.empty()) mn = que.top().first.first;

			// to
			for (int i=0; i<mp[to].size(); i++){
				int nw = mp[to][i].first;
				int nto = mp[to][i].second.first;;
				int itid = mp[to][i].second.second;
				int nid = (id*base%mod + itid)%mod;
				if (st.count(nid) != 0) continue;

				mn = min(mn,nw+val);
				if (nw+val <= mn) {
					que.push({{mn,{nid,len+1}},{from,nto}});
					st.insert(nid);
				}
				else break;
			}

			// from
			for (int i=0; i<rmp[from].size(); i++){
				int nw = rmp[from][i].first;
				int nfrom = rmp[from][i].second.first;
				int itid = rmp[from][i].second.second;
				int nid = (id + kq[len]*itid%mod)%mod;
				if (st.count(nid) != 0) continue;

				mn = min(mn,nw+val);
				if (nw+val <= mn) {
					que.push({{mn,{nid,len+1}},{nfrom,to}});
					st.insert(nid);
				}
				else break;
			}
		}

		while(!que.empty() && cnt <= maxn) {
			int from = que.top().second.first;
			int to = que.top().second.second;
			int val = que.top().first.first;
			int id = que.top().first.second.first;
			int len = que.top().first.second.second;
			que.pop();
			ans[cnt] = val;
			cnt++;
		}

		while(q--){
			int k;
			cin >> k;
			cout << ans[k] << endl;
		}
	}
	return 0;
}
// 1
// 1 2 15
// 1 1 1
// 1 1 1
// 1 2 3 4 5 6 7 8 9 10
// 11 12 13 14 15
