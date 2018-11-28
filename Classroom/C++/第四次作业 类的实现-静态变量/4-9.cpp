#include<bits/stdc++.h>
using namespace std;

class Rectangle{
public:
	int up_x,up_y;
	int down_x,down_y;
	Rectangle(){};
	Rectangle(int up_x, int up_y, int down_x, int down_y):
		up_x(up_x),up_y(up_y),down_x(down_x),down_y(down_y){};
	int GetArea(){
		return abs(up_x-down_x)*abs(up_y-down_y);
	}
};

int main(){

	return 0;
}
