#include<bits/stdc++.h>
using namespace std;

class Sole{
private:
	int life;

public:
	static int number;
	Sole(){
		assert(number == 0);
		number = 1;
	}
	Sole(int life){
		assert(number == 0);
		this->life = life;
		number = 1;
	}
	~Sole(){
		number = 0;
	}
};

int Sole::number = 0;

int main(){
	Sole *A = new Sole;
	// delete A;
	Sole *B = new Sole;
	cout<<"Delete A successfully"<<endl;
	return 0;
}
