// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
	node *lt, *rt;
	node *ls, *rs;
	node *fa;
	int val, cnt;
	bool out;
	node (int val) {
		lt = NULL;
		rt = NULL;
		ls = NULL;
		rs = NULL;
		fa = NULL;
		cnt = 1;
		out = 1;
		this->val = val;
	}
};


void oneline(node *now,int val) {
	if (now->cnt == 3) {
		// split and push some place

	}
	else { //  push one line
		if (val >= now->val) {
			node *p = now;
			while(p->rt != NULL) p=p->rt;
			p->rt = new node(val);
		}
		else {
			node *p = now;
			while(p->lt != NULL) p=p->lt;
			p->lt = new node(val);
		}
	}
}

void push(node* now, int val) {
	if (now->cnt != 4) { // not root
		if (now->out) oneline(now,val);
		else {
			if ()
		}
	}
	else { // root
		if (now->rs == NULL) {
			now->rs = new node(val);
			now->rs->fa = now;
		}
		else {
			push(now->rs,val);
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	for (int cs=1; cs<=T; cs++) {
		node *root = new node(0);
		root->cnt = 4;
		root->val = 0;
		root->out = 0;

		int n;
		cin >> n;
		for (int i=1; i<=n; i++){
			int val;
			cin >> val;
		}

	}
	return 0;
}
