// fyt
#include<bits/stdc++.h>
using namespace std;

class Point{
public:
	int x,y;

	Point();
	Point(int x,int y):x(x),y(y){};
	~Point();

	friend Point operator + (const Point& a,const Point& b);
};

Point operator + (const Point& a,const Point& b){
	Point ret;
	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return ret;
}

int main(){

	return 0;
}
