// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int INF = (1<<30)+7;
struct Node {
	int val;
	Node(int val = -INF);
};

Node merge(const Node&a, const Node&b) {
	return Node(max(a.val,b.val));
}

struct SegmentTree {
#define mid ((pl+pr)>>1)
#define lc (p<<1)
#define rc (p<<1 | 1)
	int size;
	Node *t;
	SegmentTree(int sz) {
		size = 1;
		while(size < sz) size <<= 1;
		t = new Node[2*size]();
	}

	~SegmentTree() {
		delete[] t;
	}

	Node ask(int p,int l,int r,int pl, int pr) {
		if (l > pr || r < pl) return Node(); // ??新的Node(-INF)
		if (l <= pl && r >= pr) return t[p];
	}
};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cout<<"INF = "<<INF<<endl;
	return 0;
}
