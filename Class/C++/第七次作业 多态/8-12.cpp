#include<iostream>
using namespace std;

class VirtualBaseClass{
public:
	VirtualBaseClass() {
		cout << "VirtualBaseClass is created." << endl;
	}
	virtual ~VirtualBaseClass() {
		cout << "VirtualBaseClass is deleted." << endl;
	}
};
class BaseClass{
public:
	BaseClass() {
		cout << "BaseClass is created." << endl;
	}
	~BaseClass() {
		cout << "BaseClass is deleted." << endl;
	}
};


class DerivedClass: public BaseClass {
public:

};

class VirtualDerivedClass: public VirtualBaseClass {
public:

};

inline void test1(){
	DerivedClass a;
	BaseClass *p = &a;
	delete p;
}

inline void test2(){
	VirtualDerivedClass a;
	VirtualBaseClass *p = &a;
	delete p;
}

int main(){
	test1();
	test2();
	return 0;
}
