#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
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
>>>>>>> b171952b18861a51056c058ba3b76cf59409cedd
}
