#include<iostream>
using namespace std;

class BaseClass{
public:
	void fn1(){
		cout<<"FN1-b"<<endl;
	}
	void fn2(){
		cout<<"FN2-b"<<endl;
	}
};

class DerivedClass: public BaseClass{
public:
	void fn1(){
		cout<<"FN1-d"<<endl;
	}
	void fn2(){
		cout<<"FN2-d"<<endl;
	}
};

int main(){
	DerivedClass a;
	DerivedClass *ap = &a;
	BaseClass *bp = &a;

	ap->fn1();
	bp->fn1();
	return 0;
}
