#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 112345;
int a[maxn];
const int inf = 0x3f3f3f3f;

struct node{
    int sum,l,r,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[4*maxn+5],tree2[4*maxn+5];

void build(int p,int l,int r){
    l(p) = l;
    r(p) = r;
    if(l == r){
        tree[p].sum = 0;
        return ;
    }
    int mid = (r+l)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
}

void spread(int p){
    if(add(p) != inf){
        sum(p*2) = add(p)*(r(p*2)-l(p*2)+1);
        sum(p*2+1) = add(p)*(r(p*2+1)-l(p*2+1)+1);

        add(p*2) = add(p);
        add(p*2+1) = add(p);

		add(p) = inf;
    }
}

void change(int p,int l,int r,int d){
	if(l <= l(p) && r(p) <= r){
		sum(p) = d*(r(p)-l(p)+1);
		add(p) = d;
		return ;
	}

	spread(p);
	int mid = (r(p)+l(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
}

int ask(int p,int l,int r){
	if(l <= l(p) && r(p) <= r){
		return sum(p);
	}

	spread(p);
	int val = 0;
	int mid = (r(p)+l(p))/2;
	if(l <= mid){
		val += ask(p*2,l,r);
	}
	if(r > mid){
		val += ask(p*2+1,l,r);
	}
	return val;
}

void build2(int p,int l,int r){
    l(p) = l;
    r(p) = r;
    if(l == r){
        tree[p].sum = 0;
        return ;
    }
    int mid = (r+l)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
}

void spread2(int p){
    if(add(p) != inf){
        sum(p*2) = add(p)*(r(p*2)-l(p*2)+1);
        sum(p*2+1) = add(p)*(r(p*2+1)-l(p*2+1)+1);

        add(p*2) = add(p);
        add(p*2+1) = add(p);

		add(p) = inf;
    }
}

void change2(int p,int l,int r,int d){
	if(l <= l(p) && r(p) <= r){
		sum(p) = d*(r(p)-l(p)+1);
		add(p) = d;
		return ;
	}

	spread(p);
	int mid = (r(p)+l(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);

	sum(p) = sum(2*p)+sum(2*p+1);
}

int ask2(int p,int l,int r){
	if(l <= l(p) && r(p) <= r){
		return sum(p);
	}

	spread(p);
	int val = 0;
	int mid = (r(p)+l(p))/2;
	if(l <= mid){
		val += ask(p*2,l,r);
	}
	if(r > mid){
		val += ask(p*2+1,l,r);
	}
	return val;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,t;
    cin>>t;
	int cnt = 0;
    while(t--){
		cnt++;
		cout<<"Case "<<cnt<<':'<<endl;
        cin>>n>>m;
        for(int i=1;i<=4*n;i++){
            tree[i].add = inf;
			tree[i].sum = 0;
			tree[i].l = 0;
			tree[i].r = 0;
			tree2[i].add = inf;
			tree2[i].sum = 0;
			tree2[i].l = 0;
			tree2[i].r = 0;
        }
        build(1,1,n);
		build2(1,1,n);
        while(m--){
            string k;
            cin>>k;
            if(k == "DS"){
                int x;
                cin>>x;

            }
            else if(k == "NS"){
                int x;
                cin>>x;
			}
            else if(k == "STUDY!!"){
                int l,r;
                cin>>l>>r;

			}
        }
        cout<<endl;
    }
    return 0;
}
