// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 112345;
struct node{
	int x,y;
	int rx,ry;
	int c;
	bool operator < (node & a){
		if(this->rx != a.rx)return this->rx < a.rx;
		else return this->ry < a.ry;
	}
	node(){};
	node(int x,int y ,int c){
		this->rx = x;
		this->ry = y;
		this->c = c;
	}
};


struct node2{
	int l,r;
	int maxx,add;//区间求和
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define maxx(x) tree[x].maxx
	#define add(x) tree[x].add
}tree[maxn*4];

int a[maxn];

void build(int p,int l ,int r){
	l(p) = l;
	r(p) = r;
	if(l == r){
		maxx(p) = a[l];
		return ;
	}
	int mid = (l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	maxx(p) = max(maxx(p*2),maxx(p*2+1));
}


void change(int p,int l,int r,int d){
	if(l(p) == r(p)){
		maxx(p) = d;
		return ;
	}
	int mid = (l(p)+r(p))/2;
	if(l <= mid)change(p*2,l,r,d);
	if(r > mid)change(p*2+1,l,r,d);
	maxx(p) = max(maxx(2*p),maxx(2*p+1));
}

int ask(int p,int l,int r){
	if(l <= l(p) && r >= r(p)){
		return maxx(p);
	}
	int mid = (l(p)+r(p))/2;
	int val = -1e17;
	if(l<=mid)val = max(val,ask(p*2,l,r));
	if(r > mid)val = max(val,ask(p*2+1,l,r));
	return val;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		int x,y,c;
		memset(a,0,sizeof(a));
		vector<node> arr;
		map<int,int> rank;

		cin>>n;
		for (int i=0; i<n; i++){
			cin>>x>>y>>c;
			rank[y] = 1;
			arr.push_back(node(x,y,c));
		}
		sort(arr.begin(),arr.end());
		int index = 2;
		for(auto i=rank.begin();i!=rank.end();i++){
			i->second = index++;
		}

		arr[0].x = 2;
		for (int i=0; i<arr.size(); i++){
		    arr[i].y = rank[arr[i].ry];
		}
		for (int i=1; i<arr.size(); i++){
			if(arr[i].rx == arr[i-1].rx)arr[i].x = arr[i-1].x;
			else arr[i].x = arr[i-1].x + 1;
		}

		build(1,1,maxn-1);
		int ans = 0;
		bool first = 1;
		queue<int> que;
		for (int i=0; i<arr.size(); i++){
			if(first){
				first = 0;
				int now = ask(1,1,arr[i].y-1) + arr[i].c;
				ans = max(ans,now);
				if(now > a[arr[i].y]){
					que.push(arr[i].y);
					que.push(now);
				}
			}
			else{
				if(arr[i].x != arr[i-1].x){
					while(!que.empty()){
						int place = que.front();que.pop();
						int num = que.front();que.pop();
						if(num > a[place]){
							change(1,place,place,num);
						}
					}
				}

				int now = ask(1,1,arr[i].y-1) + arr[i].c;
				ans = max(ans,now);
				if(now > a[arr[i].y]){
					que.push(arr[i].y);
					que.push(now);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
