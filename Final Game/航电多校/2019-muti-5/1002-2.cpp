// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node {
	static const int maxn = 1e5+100;
	int node[maxn*31+100][2];
	int cnt[maxn*31+100];
	int val[maxn*31+100];
	int tot = 1;
	int num = 0;
	inline void init() {
		memset(node,0,2*(tot+2)*sizeof(int));
		memset(cnt,0,(tot+2)*sizeof(int));
		tot = 1;
		num = 0;
	}
	inline void insert(int x) {
		int p = 0;
		num++;
		for (int i=31; i>=0; i--) {
			bool d = ((x>>i)&1);
			if (!node[p][d]) node[p][d]=tot++;
			p = node[p][d];
			cnt[p]++;
		}
		val[p] = x;
	}

	inline int find(int x) {
		int p = 0;
		for (int i=31; i>=0; i--) {
			bool d = (x>>i)&1;
			if (node[p][d] && cnt[node[p][d]]>0) p = node[p][d];
			else p = node[p][d^1];
		}
		return val[p];
	}

	inline void erase(int x) {
		int p = 0;
		num--;
		for (int i=31; i>=0; i--) {
			bool d = ((x>>i)&1);
			p = node[p][d];
			cnt[p]--;
		}
	}

	inline int get() {
		int p = 0;
		for (int i=31; i>=0; i--) {
			if (node[p][0] && cnt[node[p][0]]>0) p = node[p][0];
			else p = node[p][1];
		}
		return  val[p];
	}
}tr1;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		tr1.init();
		tr2.init();
		int n;
		cin >> n;
		vector<int> a(n*2);
		for (int i=0; i<2*n; i++){
		    cin >> a[i];
			if (i < n) tr1.insert(a[i]);
			else tr2.insert(a[i]);
		}
		stack<pair<int,bool>> st;
		vector<int> ans;
		while (ans.size() < n) {
			st.push({tr1.get(),true});
			// if (tr1.num == 0)break;
			// if (tr1.num == 1) {
			// 	ans.push_back(tr2.get()^tr1.get());
			// 	break;
			// }
			while(!st.empty() && ans.size() < n){
				int val = st.top().first;
				bool d = st.top().second;
				st.pop();
				// if (tr1.num < 1) break;
				// if (tr2.num < 1) break;
				int val2, valback;
				if (d) {val2 = tr2.find(val); valback = tr1.find(val2);}
				else {val2 = tr1.find(val); valback = tr2.find(val2);}

				if (valback == val) {
					ans.emplace_back(val^val2);
					if (d) tr1.erase(val), tr2.erase(val2);
					else tr1.erase(val2), tr2.erase(val);
				}
				else {st.push({val,d}); st.push({val2,!d});}
			}
		}
		sort(ans.begin(),ans.end());
		for (int i=0; i<ans.size(); i++){
			cout << ans[i] << (i==ans.size()-1?'\n':' ');
		}
	}
	return 0;
}
