#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int insidepolygon(int vcount,POINT Polygon[],POINT q) {
 int c=0,i,n;
 LINESEG l1,l2;
 bool bintersect_a,bonline1,bonline2,bonline3;
 double r1,r2;

 l1.s=q;
 l1.e=q;
 l1.e.x=double(INF);
 n=vcount;
 for (i=0;i<vcount;i++)
 {
  l2.s=Polygon[i];
  l2.e=Polygon[(i+1)%n];
  if(online(l2,q))
   return 1; // 如果点在边上，返回1
  if ( (bintersect_a=intersect_A(l1,l2))|| // 相交且不在端点
  ( (bonline1=online(l1,Polygon[(i+1)%n]))&& // 第二个端点在射线上
  ( (!(bonline2=online(l1,Polygon[(i+2)%n])))&& /* 前一个端点和后一个端点在射线两侧 */
  ((r1=multiply(Polygon[i],Polygon[(i+1)%n],l1.s)*multiply(Polygon[(i+1)%n],Polygon[(i+2)%n],l1.s))>0) ||
  (bonline3=online(l1,Polygon[(i+2)%n]))&&     /* 下一条边是水平线，前一个端点和后一个端点在射线两侧  */
   ((r2=multiply(Polygon[i],Polygon[(i+2)%n],l1.s)*multiply(Polygon[(i+2)%n],
  Polygon[(i+3)%n],l1.s))>0)
    )
   )
  ) c++;
 }
 if(c%2 == 1)
  return 0;
 else
  return 2;
}

signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	return 0;
}
