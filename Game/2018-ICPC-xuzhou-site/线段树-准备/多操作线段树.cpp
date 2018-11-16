// fyt
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 10007;
const int maxn = 1e5+5;

int qpow(int a,int b){
	int ret = 1;
	int x = a;
	while(b){
		if(b & 1){
			ret *= x;
			ret %= mod;
		}
		x *= x;
		x %= mod;
		b>>=1;
	}
	return ret;
}

struct node{
	int sum[3];// 1 2 3
	int lazy[3];// add mul change
	int l,r;
	int len;
}tree[4*maxn+5];

void build(int p,int l,int r){
	for (int i=0; i<3; i++){
		tree[p].sum[i] = 0;
	}
	tree[p].len = r-l+1;
	tree[p].l = l;
	tree[p].r = r;
	tree[p].lazy[0] = 0;
	tree[p].lazy[1] = 1;
	tree[p].lazy[2] = 0;

	int mid = l + (r-l)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	// push_up(p)
}

void push_down(int p){
	if(tree[p].lazy[3]){

	}
}

void change(int p,int l,int r,int t,int c){
	t--;
	if(t == 0){
		if(l <= tree[p].l &&  r <= tree[p].r){
			tree[p].sum[0] += c;
			tree[p].sum[0] %= mod;
			tree[p].sum[1] += 2*c*tree[p].sum[0] + qpow(c,2);
			tree[p].sum[1] %= mod;
			tree[p].sum[2] += 3*c*tree[p].sum[1] + 3*qpow(c,2)*tree[p].sum[0] + qpow(c,3);
			tree[p].sum[2] %= mod;
			return ;
		}
		push_down(p);
		int mid =
	}
}




int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
}
