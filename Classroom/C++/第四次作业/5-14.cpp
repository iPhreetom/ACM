#include<bits/stdc++.h>
using namespace std;

class Car;
class Boat;

class Boat{
private:
	int weight;
public:
	friend void totalWeight(Boat a,Car b);
	Boat(){}
	Boat(int weight):weight(weight){}
	~Boat(){}
};

class Car{
private:
	int weight;
public:
	Car(){}
	Car(int weight):weight(weight){}
	~Car(){}
	friend void totalWeight(Boat a,Car b);
};

void totalWeight(Boat a,Car b){
	cout<<a.weight + b.weight<<endl;
}

int main(){
	Car a(10);
	Boat b(10);
	totalWeight(b,a);
	return 0;
}
