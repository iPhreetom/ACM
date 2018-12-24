#include<iostream>
using namespace std;

class Mammal {
public:
	virtual void Speak() = 0;
};

class Dog: public Mammal {
public:
	void Speak(){
		cout<<"Wong wong"<<endl;
	}
};

int main(){
	Dog pet;
	Mammal *p = &pet;
	pet.Speak();
}
