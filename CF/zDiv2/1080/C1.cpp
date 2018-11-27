// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define L lld
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int q = (1 + 2) & 2;
	cout<<"q = "<<q<<endl;
	return 0;
	long long x1,y1,x2,y2,x3,y3,x4,y4,i,j,k,l,m,n,t,x,y,z;
	for(scanf("%L",&t);t--;)
	{
		scanf("%L%L%L%L%L%L%L%L%L%L",&n,&m,&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		i=x1>x3?x1:x3,// i = max x1 x3
		j=y1>y3?y1:y3,// j = max y1 y3
		k=x2<x4?x2:x4,// k = min x2 x4
		l=y2<y4?y2:y4;// l = min y2 y4
		x=((x2-x1)%2+(y2-y1)%2 < 1 & (x1+y1&1))// 如果面积是奇数，并且起始位置是黑色 x++
			+(x2-x1+1)*(y2-y1+1)/2; // 白色涂抹的面积
		// x白色实际涂抹的面积
		y=((x4-x3)%2+(y4-y3)%2 < 1 &!(x3+y3&1))
			+(x4-x3+1)*(y4-y3+1)/2;
		// y黑色实际涂抹面积
		x -= i>k|j>l?0:// 不相交
			((k-i)%2+(l-j)%2<1&(i+j&1))
			+(k-i+1)*(l-j+1)/2;
		printf("%L %L\n",n*m/2+n*m%2+x-y,n*m/2-x+y);
	}
	return 0;
}
