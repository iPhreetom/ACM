// –         能够管理直线,三角形,矩形,椭圆等图形
//
// –         能够计算各图形的周长和面积
//
// –         能够添加删除图形，显示已有图形信息。

#include<bits/stdc++.h>
using namespace std;


class Shape {
public:
	virtual double GetPerim() = 0;
	virtual double GetArea() = 0;
	virtual string GetName() = 0;
};

class Rectangle: public Shape {
private:
	int width;
	int height;
	string name = "Rectangle";
public:
	Rectangle(int a,int b):width(a),height(b){};
	double GetPerim(){
		return (width+height)*2;
	}
	double GetArea(){
		return width*height;
	}
	string GetName(){
		return name;
	}
};

class Circle: public Shape {
private:
	double radius;
	string name = "Circle";
	const double pi = 3.14;
public:
	Circle(double r):radius(r){}
	double GetPerim(){
		return 2*pi*radius;
	}
	double GetArea(){
		return pi*radius*radius;
	}
	string GetName(){
		return name;
	}
};

class Line: public Shape {
private:
	double length;
	string name = "Line";
public:
	Line(double length):length(length){}
	double GetPerim(){
		return length;
	}
	double GetArea(){
		return 0;
	}
	string GetName(){
		return name;
	}
};

class Ellipse: public Shape {
private:
	double a;
	double b;
	string name = "Ellipse";
	const double pi = 3.14;
public:
	Ellipse(double a, double b):a(a),b(b){}
	double GetPerim(){
		return 2*pi*b+4*abs(a-b);
	}
	double GetArea(){
		return pi*a*b;
	}
	string GetName(){
		return name;
	}
};

class GraphSystem {
public:
	vector<Shape*> v;
	void show() {
		for (int i=0; i<v.size(); i++){
			cout<<v[i]->GetName()<<": "<<endl;
			cout<<"\t Area: "<<v[i]->GetArea()<<endl;
			cout<<"\t Perim: "<<v[i]->GetPerim()<<endl;
		}
	}
};


int main(){
	GraphSystem S;
	Line L(1);
	Shape *p;
	p = &L;
	S.v.push_back(p);
	S.show();
	return 0;
}
