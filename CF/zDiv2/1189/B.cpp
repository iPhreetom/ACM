// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n,0);
	for (int i=0; i<n; i++){
	    cin >> v[i];
	}
	sort(v.rbegin(),v.rend());
	deque<int> que;
	for (int i=0; i<v.size(); i++){
		if (i%2==1) {
			que.push_front(v[i]);
		}
		else {
			que.push_back(v[i]);
		}
	}

	if (que[0] >= que.back()+que[1] || que.back() >= que.front()+que[n-2]) {
		cout << "NO" << endl;
	}
	else {
		for (int i=1; i<que.size()-1; i++){
			if (que[i] >= que[i-1] + que[i+1]) {
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
		for (int i=0; i<que.size(); i++){
			cout << que[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
