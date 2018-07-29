// CF 912D Fishes
// 	一句话描述：
// 		基于优先队列的BFS
// 	知识点：
// 		结构体的构造函数
// 		结构体的重载运算符
// 		结构体的优先队列写法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<double,double> pdd;



ll n,m,r,k;
double ans;
map<pii,ll> book;
struct Node {
	ll x,y;
	double val;
	Node(ll x,ll y,double val):x(x),y(y),val(val){}
	bool operator<(const Node &a) const{
		return this->val < a.val;
	}
};

double get_val(ll x,ll y){
	// double xx =	min(min(x,r-(n-x+1)),r);
	// double yy = min(min(y,r-(m-y+1)),r);
	double xx=min(min(1.00*x,n-x+1.00),min(n-r*1.00+1,1.00*r));
	double yy=min(min(1.00*y,m-y+1.00),min(m-r*1.00+1,1.00*r));
	double ret = (xx*yy)/(n-r+1)/(m-r+1);
	return ret;
}
priority_queue<Node> que;
ll Next[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>r>>k;
	que.push({n-r+1,m-r+1,get_val(n-r+1,m-r+1)});
	book[make_pair(n-r+1,m-r+1)]=1;
	while(k--){
		Node tp = que.top();
		que.pop();
		ans+=tp.val;
		// cout<<"("<<tp.x<<' '<<tp.y<<")"<<endl;
		for(ll i=0;i<4;i++){
			ll xx = tp.x + Next[i][0];
			ll yy = tp.y + Next[i][1];
			if(book.count(make_pair(xx,yy)) == 0 && xx>=1 && yy>=1 && xx <= n && yy <= m){
				que.push({xx,yy,get_val(xx,yy)});
				book[make_pair(xx,yy)]=1;
			}
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}
