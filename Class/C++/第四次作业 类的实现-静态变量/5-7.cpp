#include<bits/stdc++.h>
using namespace std;

class Cat{
private:
	int CatID;
public:
	static int HowManyCats;

	Cat(){
		HowManyCats++;
	}
	Cat(int CatID):CatID(CatID){
		HowManyCats++;
	}
	~Cat(){
		HowManyCats--;
	}

	int GetCatID(){
		return CatID;
	}
	static int GetHowMany(){
		return HowManyCats;
	}
};

int Cat::HowManyCats = 0;

int main(){
	Cat Tom(1);
	Cat Hello_Kitty(2);
	Cat DoLaAMem(3);
	cout<<"Tom's ID is "<<Tom.GetCatID()<<endl;
	cout<<"Tom.GetHowMany() = "<<Tom.GetHowMany()<<endl;
	cout<<"Hello_Kitty's ID is "<<Hello_Kitty.GetCatID()<<endl;
	cout<<"Hello_Kitty.GetHowMany() = "<<Tom.GetHowMany()<<endl;
	cout<<"DoLaAMem's ID is "<<DoLaAMem.GetCatID()<<endl;
	cout<<"Hello_Kitty.GetHowMany() = "<<Tom.GetHowMany()<<endl;
	return 0;
}
