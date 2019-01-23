#include<iostream>
using namespace std;

class A {
public:
	int s = 110;
	A() {
		cout<<"Created"<<endl;
	}
	A(int t) {
		s = t;
		cout<<"Created"<<endl;
	}
	~A() {
		cout<<"Delete"<<endl;
	}
};

int main() {
	a.~A();
	a.~A();
	return 0;
}
