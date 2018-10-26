// fyt

// 题意：
// 	给出二维空间的点，求矩形个数，要求找到两个不接触的矩形，使得覆盖面积最大
// 知识点：
// 	基本操作：
// 		建立struct然后排序，使得点有一定顺序
// 	求矩形的方法：
// 		两点法，确定对角线，然后询问另外两个点是否存在
// 	矩形位置关系：
// 		check函数，多组判断法
// 	计算机和写法：
// 		多用vector和struct


#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct point{
	int x,y;
	bool operator < (const point& b){
		if(x == b.x)return y<b.y;
		return x<b.x;
	};
	point(){};
	point(int x,int y):x(x),y(y){};
};

struct rec{
	point up,down;
	int area;
	rec(){};
	rec(point a,point b,int c):down(a),up(b),area(c){};
};

bool vis[301][301];

int check(rec &a,rec &b){
	if(a.down.x > b.up.x || a.down.y > b.up.y){
		return 1;
	}
	if(b.down.x > a.up.x || b.down.y > a.up.y){
		return 1;
	}
	// a is small
	if(a.down.x > b.down.x
		&& a.down.y > b.down.y
		&& a.up.x < b.up.x
		&& a.up.y < b.up.y){

		return 2;
	}
	if(b.down.x > a.down.x
		&& b.down.y > a.down.y
		&& b.up.x < a.up.x
		&& b.up.y < a.up.y){

		return 3;
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	// point a(1,1);
	// point b(1,1);
	// if(a<b){
	// 	cout<<"n = "<<n<<endl;
	// }

	while(1){
		memset(vis,0,sizeof(vis));
		cin>>n;
		if(n == 0)break;

		vector<point> p;
		for (int i=0; i<n; i++){
			int x,y;
			cin>>x>>y;
			vis[x][y] = 1;
			p.push_back(point(x,y));
		}
		sort(p.begin(),p.end());

		vector<rec> r;
		for (int i=0; i<p.size(); i++){
			for (int j=i+1; j<p.size(); j++){
			    int x1 = p[i].x;
				int x2 = p[j].x;
				int y1 = p[i].y;
				int y2 = p[j].y;
				if(x2 > x1 && y2 > y1 && vis[x2][y1] && vis[x1][y2]){
					int area = (x2-x1)*(y2-y1);
					r.push_back(rec(p[i],p[j],area));
				}
			}
		}

		int ans = -1;
		// cout<<"r.size() = "<<r.size()<<endl;
		for (int i=0; i<r.size(); i++){
			for (int j=i+1; j<r.size(); j++){
				int t = check(r[i],r[j]);
				int a1 = r[i].area;
				int a2 = r[j].area;

				if(t == 1){// dif
					ans = max(ans,a1+a2);
				}
				if(t == 2){// i is small
					ans = max(ans,a2);
				}
				if(t == 3){// j is small
					ans = max(ans,a1);
				}
				// if(t != 0){
				// 	cout<<a1<<' '<<a2<<endl;
				// }
			}
		}

		if(ans == -1){
			cout<<"imp"<<endl;
		}
		else cout<<ans<<endl;
	}

	return 0;
}
