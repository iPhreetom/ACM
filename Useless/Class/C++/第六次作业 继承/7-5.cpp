#include<iostream>
using namespace std;

class Shape {
public:
	virtual int GetArea() = 0;
};

class Rectangle: public Shape{
private:
	int width;
	int height;
public:
	Rectangle();
	Rectangle(int width=0,int height=0):width(width),height(height){};
	~Rectangle();
	int GetArea(){
		return width*height;
	}
};

class Circle: public Shape{
private:
	const double PI = 3.14;
	double radius;
public:a
	Circle();
	Circle(double radius):radius(radius){};
	~Circle();
	int GetArea(){
		return radius*radius*PI;
	}
};


int main(){

	return 0;
}
