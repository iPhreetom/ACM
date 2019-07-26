#include<iostream>
using namespace std;

class Shape {
public:
	virtual double GetPerim() = 0;
	virtual double GetArea() = 0;
};

class Rectangle: public Shape {
private:
	int width;
	int height;
public:
	Rectangle(int a,int b):width(a),height(b){};
	double GetPerim(){
		return (width+height)*2;
	}
	double GetArea(){
		return width*height;
	}
};

class Circle: public Shape {
private:
	double radius;
	const double pi = 3.14;
public:
	Circle(double r):radius(r){}
	double GetPerim(){
		return 2*pi*radius;
	}
	double GetArea(){
		return pi*radius*radius;
	}
};

int main(){

}
