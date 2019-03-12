#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;

	auto getNext = [&](auto &v,auto &next) {
		if(v.size() <= 1)return;
		next[0] = -1;
		next[1] = 0;
		int cnt = 0;
		int pos = 2;
		while(pos < next.size()) {
			if(v[pos-1] == v[cnt]) {
				next[pos++] = ++cnt;
			}
			else if(cnt > 0) {
				cnt = next[cnt];
			}
			else {
				next[pos++] = 0;
			}
		}
	};
	auto findnum = [&](auto &a,auto &b,auto &next) -> int{
		getNext(b,next);
		int j = 0;
		int ans = 0;
		for (int i=0; i<a.size(); i++){
			while(j && b[j] != a[i])j = next[j];
			if(b[j] == a[i])j++;
			if(j == b.size())return i-j+2;
		}
		return -1;
	};

	while(cin >> s) {
		vector<int> next(s.size() ,0);
		getNext(s,next);
		cout << "next.back() = " << next.back() << endl;
		if(next.back() == 0) {
			cout << s.size() << endl;
		}
		else {
			cout << s.size() - next.back() -1 << endl;
		}
	}
	return 0;
}
