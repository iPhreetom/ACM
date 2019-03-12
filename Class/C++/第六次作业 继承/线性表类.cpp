#include<iostream>

class array{
protected:
	int vector[1000000];
public:
	virtual void push() = 0;
	virtual void pop() = 0;
};

class stack: public array{
private:
	int left_point = 1;
	int right_point = 1;
public:
	void push(int element){
		vector[right_point] = element;
		++right_point;
	}
	void pop(){
		--right_point;
	}
	int size(){
		return right_point-left_point;
	}
	int top(){
		return vector[right_point];
	}
};

class queue: public array{
private:
	int left_point = 1;
	int right_point = 1;
public:
	void push(int element){
		vector[right_point] = element;
		++right_point;
	}
	void pop(){
		++left_point;
	}
	int size(){
		return right_point-left_point;
	}
	int front(){
		return vector[left_point];
	}
};

int main(){

}
