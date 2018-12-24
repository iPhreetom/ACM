#include<bits/stdc++.h>
using namespace std;

class hero {
protected:
	int number;
	int position;
	int hp;
	int ad;
public:
	hero(){}
	hero(int number, int position, int hp, int ad){
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
	}
	~hero(){}
	virtual void forward() = 0;
	virtual int attack() = 0;
	virtual int counterattact() = 0;
	virtual void bigboom() = 0;
};

class dragon: public hero {
private:
public:
	dragon(){}
	dragon(int number, int position, int hp, int ad){
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
	}
	~dragon(){}

	static double morale;
	void forward(){

	}
	int attack(){

	}
	int counterattact(){

	}
	void bigboom(){

	}
};

double dragon::morale = 0;

void War(){
	dragon a;
	hero *p = &a;

}


int main(){
	int case_number;

	cin>>case_number;
	for (int i=1; i<=case_number; i++){
		cout<<"Case "<<case_number<<":\n";
		War();
	}
	return 0;
}
