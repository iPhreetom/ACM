#include<bits/stdc++.h>
using namespace std;

class hero {
protected:
	int number;
	int position;
	int hp;
	int ad;
public:
	hero(){};
	hero(int number, int position, int hp, int ad){
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
	}
	~hero(){};
	virtual void forward() = 0;
	virtual int attack() = 0;
	virtual int counterattact() = 0;
	virtual void bigboom() = 0;
};

class dragon: public hero {
private:

public:
	dragon(){};
	dragon(int number, int position, int hp, int ad){
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
	}
	~dragon(){};
	void forward(){
		cout<<"Dragon go"<<endl;
	}
	int attack(){
		return 1;
	}
	int counterattact(){
		return 1;
	}
	void bigboom(){

	}
};


void War(){
	// queue<hero*> que;
	// dragon a;
	// hero *p = &a;
	// que.push(p);
	// que.front()->forward();
	
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
