#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, k;
	cin >> n >> k;
	if(k > n) {
		cout << "NO" << endl;
		return 0;
	}

	priority_queue<int> v;
	int now = n;
	int index = 0;
	while(now) {
		if((now & 1)) {
			v.push((1<<(index)));
		}
		now >>= 1;
		index++;
	}
	if(v.size() > k) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	while(v.size() < k) {
		int tp = v.top();
		v.pop();
		v.push(tp/2);
		v.push(tp/2);
	}

	while(!v.empty()) {
		cout << v.top() << ' ';
		v.pop();
	}cout << endl;
	return 0;
}
