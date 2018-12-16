#include<iostream>
using namespace std;

class object {
protected:
	int weight;
public:
	object(){
		cout<<"Creating an object"<<endl;
	}
	object(int weight){
		this->weight = weight;
		cout<<"Creating an object"<<endl;
	}
	~object(){
		cout<<"Delete an object"<<endl;
	}
};

class box: public object{
private:
	int height;
	int width;
public:
	box(){
		cout<<"Creating a box"<<endl;
	}
	box(int weight,int height,int width){
		this->weight = weight;
		this->height = height;
		this->width = width;
		cout<<"Creating a box"<<endl;
	}
	~box(){
		cout<<"Delete a box"<<endl;
	}
};


int main(){
	box a;
	return 0;
}
