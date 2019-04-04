#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;

struct treap {
	int l,r;
	int cnt;
	int val;
	int size;
	int dat;
} a[maxn];

int root;
int tot;
int n;
int inf = 0x7fffffff;

int New(int val) {
	a[++tot].val = val;
	a[tot].dat = rand();
	a[tot].size = a[tot].cnt = 1;
	return tot;
}

void Update(int p){
	a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
}


void Build() {
	tot = 0;
	root = 1;
	New(-inf);
	New(inf);
	a[root].r = 2;
	Update(root);
}

// 查询值是第几大
int GetRank(int p,int val) {
	// defualt p is root
	if(p == 0) return 0;
	if(val == a[p].val) return a[a[p].l].size + 1;
	if(val < a[p].val) return GetRank(a[p].l, val);
	return GetRank(a[p].r, val) + a[a[p].l].size + a[p].cnt;
}

// 查询第k大是谁
int GetVal(int p, int rank) {
	if (p == 0) return inf;
	if (a[a[p].l].size >= rank) return GetRank(a[p].l, rank);
	if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
	return GetVal(a[p].r, rank - a[a[p].l].size - a[p].cnt);
}

void RotateWithLeftSon(int &p) {
	int q = a[p].l;
	a[q].l = a[p].r;
	a[p].r = p;
	p = q;
	Update(a[p].r);
	Update(p);
}

void RotateWithRightSon(int &p) {
	int q = a[p].r;
	a[p].r = a[q].l;
	a[q].l = p;
	p = q;
	Update(a[p].l);// origin-father will be in the origin-son's left son;
	Update(p);
}

void Insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return ;
	}

	if (a[p].val == val) {
		a[p].cnt++;
	}
	else if(a[p].val < val) {
		Insert(a[p].r, val);
		if (a[p].dat < a[a[p].r].dat) RotateWithRightSon(p);
	}
	else {
		Insert(a[p].l, val);
		if (a[p].dat < a[a[p].l].dat) RotateWithLeftSon(p);
	}
	Update(p);
}

// int GetPre(int val) {
// 	int ans = 1;// a[1].val = -inf
// 	int p = root;
// 	while (p) {
// 		if( val == a[p].val) {
// 			if(a[p].l > 0) {
// 				p = a[p].l;
// 				while(a[p].r > 0)
// 					p = a[p].r;
// 				ans = p;
// 			}
// 			break;
// 		}
// 		if(a[p].val < val && a[p].val > a[ans].val)  ans = p;
// 	}
// 	return a[ans].val;
// }
//
// int GetNext(int val) {
// 	int ans = 2;// a[2].val = inf
// 	int p = root;
// 	while(p) {
// 		if(val == a[p].val) {
// 			if(a[p].r > 0) {
// 				p = a[p].r;
// 				while(a[p].l > 0) p = a[p].l;
// 				ans = p;
// 			}
// 			break;
// 		}
// 		if(a[p].val > val && a[p].val < a[ans].val) ans = p;
// 		p = val < a[p].val ? a[p].l : a[p].r;
// 	}
// }
//
// void Remove (int &p, int val) {
// 	if(p == 0) return ;
// 	if(val == a[p].val) {
// 		if(a[p].cnt > 1) {
// 			a[p].cnt --;
// 			Update(p);
// 			return ;
// 		}
// 		if(a[p].l || a[p].r){
// 			if(a[p].r == 0|| a[a[p].l].dat > a[a[p].r].dat)
// 				RotateWithLeftSon(p);
// 			else
// 				RotateWithRightSon(p);
// 		}
// 		else p = 0;
// 		return ;
// 	}
// 	val < a[p].val? Remove(a[p].l, val) : Remove(a[p].r, val);
// 	Update(p);
// }

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Build();
	cin >> n;
	while(n--) {
		int opt, x;
		cin >> opt >> x;
		switch(opt){
			case 1:
				Insert(root, x);
				break;
			case 2:
				Remove(root, x);
				break;
			case 3:
				cout << GetRank(root,x)-1 << '\n';
				break;
			case 4:
				cout << GetVal(root, x+1) << '\n';
				break;
			case 5:
				cout << GetPre(x) << '\n';
				break;
			case 6:
				 cout << GetNext(x) << '\n';
				 break;
			defualt:
				break;
		}
	}
}
