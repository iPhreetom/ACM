// fyt
#include<bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 112345;

struct node{
	int l,r;
	int sum,add;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
}tree[maxn*4];

int n,q;

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		sum(p) = 0;
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p) = sum(p*2)+sum(p*2+1);
}


void change(int p,int l,int r,int d){
	if(l <= l(p) && r >= r(p)){
		sum(p) += d*(r(p)-l(p)+1);
		return ;
	}
	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
}

int ask(int p,int l,int r){

	if(l <= l(p) && r >= r(p)){
		return sum(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = 0;
	if(l<=mid)val += ask(p*2,l,r);
	if(r > mid)val += ask(p*2+1,l,r);
	return val;
}

int main () {
    int n,x,y;
    while(scanf("%d%d%d",&n,&x,&y) != EOF) {
        int ans = 0;

        vector<pair<int,int> > mp2(n);
        vector<int> v(n+1);

        for (int i=1; i<=n; i++) {
            scanf("%d",&v[i]);
            mp2[i-1] = {v[i],i};
        }

		int cnt = 1;
        sort(mp2.begin(),mp2.end());
        for (int i=0; i<n; i++) {
			if (i != 0) {
				if (mp2[i-1].first != mp2[i].first) {
					cnt++;
				}
			}
            v[mp2[i].second] = cnt;
        }

        build(1,1,n+1);
        for (int i=1; i<=n; i++) {
            ans += ask(1,v[i]+1,n);
            change(1,v[i],v[i],1);
        }

        printf("%d\n",ans*min(x,y));
    }
}