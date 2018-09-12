#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
    double x, y;
} a[4];

bool cmp(point a, point b)
{
    if (a.x != b.x)
        return a.x < b.x; //如果，横坐标不相等，所有点按横坐标升序排列
    return a.y < b.y;//如果横坐标相等，所有点按纵坐标升序排列
}

double TwoPointDiatance(point a, point b)//计算两点之间的距离
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

bool IsRightAngle(point a, point b, point c)//判断是否为直角
{
    double x;
    x = (a.x - b.x)* (a.x - c.x) + (a.y - b.y)*(a.y - c.y);
    if (x < 0.00001)
        return 1;
    else
        return 0;
}

int main()
{
    int t, k;
    double s1, s2, s3, s4;
    cin >> t;
    while (t--)
    {
		int n;
		cin>>n;
		if(n!= 4){
			for (int i=0; i<n; i++){
			    int t;
				cin>>t>>t;
			}
			cout<<"NO"<<endl;
			continue;
		}


        for (int i = 0; i < 4; i++)
            cin >> a[i].x >> a[i].y;

        //确定点，排序，给点确定标号
        sort(a, a + 4, cmp);

        //确定边
        s1 = TwoPointDiatance(a[0], a[2]);
        s2 = TwoPointDiatance(a[0], a[1]);
        s3 = TwoPointDiatance(a[3], a[1]);
        s4 = TwoPointDiatance(a[2], a[3]);

        //分析是否为正方形
        if (s1 == s2&&s3 == s4&&s1 == s2&&s1 != 0 && IsRightAngle(a[0], a[1], a[2]))//三个条件同时满足（1：四条边相等，2：边不为0，3：有一个直角）
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
