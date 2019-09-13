// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

// 01 Trie
const int MAXN = 1e5+100;
struct Trie {
    int t[31 * MAXN][3], sz;
	int val[MAXN*31];
	vector<int> index[MAXN*31];

    inline void init(int n) {
        memset(t, 0, 3 * (sz + 2) * sizeof(int));
		memset(val, -1, 3 * (sz + 2) * sizeof(int));
        sz = 1;
    }

    inline void insert(int x, int pos) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            bool d = (x >> i) & 1;
            if (!t[p][d]) t[p][d] = sz++;
            p = t[p][d];
			t[p][2]++;
        }
		if (val[p] == -1 && !index[p].empty())index[p].clear();
		val[p] = x;
		index[p].push_back(pos);
    }

	inline void erase(int x) {
		int p = 0;
		for (int i = 30; i >= 0; i--) {
            bool d = (x >> i) & 1;
			p = t[p][d];
			t[p][2]--;
        }
		index[p].pop_back();
	}

	inline int find(int x) {
		int p = 0;
		for (int i = 30; i >= 0; i--) {
            bool d = (x >> i) & 1;
            if (t[p][d] && t[t[p][d]][2]) p = t[p][d];
            else p = t[p][d^1];
        }
		return val[p];
	}

	inline int findindex(int x) {
		int p = 0;
		for (int i = 30; i >= 0; i--) {
            bool d = (x >> i) & 1;
            if (t[p][d] && t[t[p][d]][2]) p = t[p][d];
            else p = t[p][d^1];
        }
		return index[p].back();
	}
}tr1,tr2;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("C:\\Users\\I freedom\\Desktop\\hdu2019contest5\\1002\\data\\1.in","r",stdin);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		tr1.init(n);
		tr2.init(n);
		vector<int> inst(2*n,0);
		vector<int> a(n*2);
		for (int i=0; i<n; i++){
			cin >> a[i];
			tr1.insert(a[i],i);
		}
		for (int i=n; i<2*n; i++){
		    cin >> a[i];
			tr2.insert(a[i],i);
		}

		vector<int> ans;
		set<int> res;
		stack<int> st;
		for (int i=0; i<2*n; i++){
			res.insert(i);
		}

		st.push(*res.begin());
		inst[*res.begin()] = 1;
		res.erase(*res.begin());

		while (!st.empty()) {
			int top = st.top();
			st.pop();
			if (!inst[top]) continue;

			int index;
			if (top<n) index = tr2.findindex(a[top]);
			else index = tr1.findindex(a[top]);
			res.erase(index);
			if (inst[index]) {
				ans.push_back(a[index]^a[top]);
				tr1.erase(a[min(index,top)]);
				tr2.erase(a[max(index,top)]);
				inst[index]=0;
				inst[top]=0;
				if (st.empty() && !res.empty()) {
					st.push(*res.begin());
					inst[*res.begin()]=1;
					res.erase(*res.begin());
				}
			}
			else {
				st.push(top);
				st.push(index);
				inst[index]=1;
				inst[top]=1;
			}
		}

		sort(ans.begin(),ans.end());
		bool f = 1;
		for (int i=0; i<ans.size(); i++) {
			if (f) cout << ans[i] , f = 0;
			else cout << ' ' << ans[i] ;
		}cout << endl;
	}
	return 0;
}
