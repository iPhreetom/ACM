// 使用 rbegin() - rend()
// 反向迭代器 ： rbegin(): 最后一个元素
// 		  :  rend(): 第一个元素前一个位置
// 		  在sort的时候，可以方便的从大到小排序
// 		  （resever()也可以达到同样的效果）

// ~   取反操作
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 100005;


typedef long long ll;
typedef pair<int, int> pii;

int a[MAX];
int b[MAX];
ll dp1 [5005][55];
ll dp2 [5005][55];
const ll INF = 1000000000000000000;
// index, # of processors, wiggle room
map<int, vector<int> > m;
main() {
	// freopen("a.in", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}

	// 记录 每种消耗 对应的所有 核心数目
	for (int i=0; i<n; i++) {
		m[a[i]].push_back(b[i]);
	}

	// 记录 消耗类型xd
	// 在 map 中的核心数目从大向小排序
	vector<int>xd;
	for (auto i=m.begin(); i!=m.end(); i++) {
		xd.push_back(i->first);
		sort(m[i->first].rbegin(), m[i->first].rend());
	}

	// 开始动态规划
	// 初始化
	for (int i=0; i<5005; i++) {
		for (int j=0; j<55; j++) {
			dp1[i][j] = dp2[i][j] = INF;
		}
	}

	// 开头为0
	// ~(-1) == 0
	dp1[0][0] = dp2[0][0] = 0;
	for (int i=xd.size()-1; ~i; i--) {
		int power = xd[i];
		vector <int> processors = m[power];
		vector <ll> pref;
		pref.push_back(0);

		// 遍历 所有 核心数
		for (int j=0; j<processors.size(); j++){

			// 把核心数做前缀和
			// 在 perf里，保存，从大到小排序的数列 的 前缀和
			if (pref.size()==0) pref.push_back(processors[j]);
			else pref.push_back(pref.back()+processors[j]);
		}


		// ???????????????????
		for (int j=0; j<5005; j++) {

			for (int z=0; z<55; z++) {
				dp2[j][z] = dp1[j][z];
				dp1[j][z] = INF;
			}
		}
		for (int j=0; j<5005; j++) {
			for (int z=0; z<55; z++) {
				for (int k=0; k<=processors.size(); k++) {
					// using k
					int frees = processors.size() - k;

					ll newsum = dp2[j][z] + power * k; // new power sum
					ll newden = j + pref[k]; // new # of procs
					if (frees > z) { continue; }
					if (newden > 5000) { continue; }
					dp1[newden][z+k-frees] = min(dp1[newden][z+k-frees], newsum);
				}
			}
		}
	}

	// 计算出55 * 5005 个解，暴力查询最小值
	double ans = INF;
	for (int i=1; i<5005; i++){
		for (int j=0; j<55; j++) {

			ans = min(ans, dp1[i][j]/(double)i);
		}
	}
	cout << fixed << setprecision(0) << ceil(1000*ans) << '\n';
	return 0;
}
