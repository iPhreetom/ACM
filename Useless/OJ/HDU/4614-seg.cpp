// 线段树二分
// 总结：
// 	更换方法以后，写法异常好写，并且BUG更加明显
// 		如果只有复杂的思路，那么很难写对
// 		最好想出来 怎么样会更加好写
// 	尽量使用固定点的二分，而非两边都会移动的二分。


#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxn = 51234;
int a[maxn];
const int inf = 0x3f3f3f3f;

struct node{
    int sum,l,r,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[4*maxn+5];

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


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=4*maxn;i++){
            tree[i].add = inf;
			tree[i].sum = 0;
			tree[i].l = 0;
			tree[i].r = 0;
        }
        build(1,1,n);
        while(m--){
            int k;
            cin>>k;
            if(k == 1){
                int p,x;
                cin>>p>>x;
                p++;

                // judge
				int num = ask(1,p,n);
				int zero = n-p+1 - num;
				x = min(x,zero);

				if(zero == 0) {
					cout<<"Can not put any one."<<endl;
				}
				else {
					int l,r;
					// repeat
					int posl = p;
					l = p, r = n+1;
					while(l+1 < r) {
						int mid = l+(r-l)/2;
						int num = mid-p+1;
						int one = ask(1,p,mid);
						int zero = num-one;
						if(zero > 1 || (zero == 1 && ask(1,mid,mid) == 1)) r = mid;
						else l = mid;
					}
					posl = l;

					// repeat
					int posr = p;
					l = p, r = n+1;
					while(l+1 < r) {
						int mid = l+(r-l)/2;
						int num = mid-p+1;
						int one = ask(1,p,mid);
						int zero = num-one;
						if(zero > x || (zero == x && ask(1,mid,mid) == 1)) r = mid;
						else l = mid;
					}
					posr = l;

					cout<<posl-1<<' '<<posr-1<<endl;
					change(1,posl,posr,1);
				}
            }
            else if(k == 2){
                int l,r;
                cin>>l>>r;
                l++;
                r++;
                cout<<ask(1,l,r)<<endl;
                change(1,l,r,0);
            }
            // for(int i=1;i<=n;i++){
            //     cout << "show ask(1,i,i) : " << ask(1,i,i) << endl;
            // }
        }
        cout<<endl;
    }
    return 0;
}
