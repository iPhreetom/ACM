// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct Tbit {
	int size;
	int t[112345];

	void init(int sz) {
		size = sz+1;
		memset(t,0,(sz+2)*sizeof(int));
	}

	int lowbit(int x) {return x&(-x);}

	void add(int p,int x) {
		if (p <= 0) return;
		for (; p<=size; p+=lowbit(p)) t[p] += x;
	}

	int get(int p) {
		int sum = 0;
		for (;p>0; p-=lowbit(p)) sum+=t[p];
		return sum;
	}
};

int pre[112345];
int suf[112345];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;

	vector<int> a(n+1);
	typedef pair<int,int> pii;
	priority_queue<pii,vector<pii>,greater<pii>> que;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		que.push(make_pair(a[i],i));
	}

	Tbit bt;
	bt.init(1e5+1);
	for (int i=1; i<=n; i++) {
		bt.add(a[i],1);
		int dif = bt.get(1e5+1)-bt.get(a[i]);
		pre[i] = dif;
	}
	bt.init(1e5+1);
	for (int i=n; i>=1; i--) {
		bt.add(a[i],1);
		int dif = bt.get(1e5+1)-bt.get(a[i]);
		suf[i] = dif;
	}

	int sum = 0;
	while(!que.empty()) {
		int val = que.top().first;
		int index = que.top().second;
		que.pop();
		sum += min(suf[index],pre[index]);
	}
	cout << sum << endl;
	return 0;
}
