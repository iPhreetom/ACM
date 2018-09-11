#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#include <windows.h>
using namespace std;



class sys{
public:
	class node{
	public:
		string phone;
		string name;
		set<string> lis;
		deque<string> message;
		node(){};
		node(string &name , string &phone){
			this->phone = phone;
			this->name = name;
		};
	};

	sys(){};

	void begin(string file){
		ifstream fin(file);
		string address,name,phone,member;
		int num;
		while(fin>>address){
			fin>>name>>phone>>num;
			database[address] = (node){name,phone};
			for (int i=0; i<num; i++){
				fin>>member;
				database[address].lis.insert(member);
			}
		}
		fin.close();
	}

	void end(string file){
		ofstream fout(file);
		for(auto i:database){
			fout<<i.first<<' ';
			auto &t = i.second;
			fout<<t.name<<' '<<t.phone<<' ';
			fout<<t.lis.size()<<endl;
			for(auto j:t.lis){
				fout<<j<<' ';
			}
			fout<<endl;
		}
		fout.close();
	}

	bool check(){

	}


	void send(string &aim,string &message){
		database[aim].message.push_back(message);
		for(auto i: database[aim].lis){
			send(aim,message);
		}
	}

	bool list_information(string &address){
		if(database.count(address)==0){
			return false;
		}
		else{
			if(!database[address].name.size() == 0){
				cout<<"name = "<<database[address].name<<endl;
			}
			if(!database[address].phone.size() == 0){
				cout<<"phone = "<<database[address].phone<<endl;
			}
			if(!database[address].lis.empty()){
				cout<<"The member in it: "<<endl;
				for(auto i:database[address].lis){
					cout<<i<<endl;
				}
			}
			return true;
		}
	}

	bool add_gruop(string &address , string &group){
		database[group].lis.insert(address);
	}

	bool delete_gruop(string &address , string &group){
		database[group].lis.erase(address);
	}

	bool add_person(string &address , string &name , string &phone){
		if(database.count(address) != 0)return false;
		database[address] = (node){name,phone};
		return true;
	}

	bool delete_person(string &address){
		if(database.count(address) != 0)return false;
		database.erase(address);
		return true;
	}


private:
	map<string,node> database;
};




int main(){
	sys bjtu;
	if(!fopen("data.txt","r")){
		auto f = fopen("data.txt","w");
		fclose(f);
	}
	bjtu.begin("data.txt");

	while(1){
		system("cls");
		cout<<"[1] - add person"<<endl;
		cout<<"[2] - remove person"<<endl;
		cout<<"[3] - join gruop"<<endl;
		cout<<"[4] - leave gruop"<<endl;
		cout<<"[5] - list information"<<endl;
		cout<<"[0] - Exit"<<endl;
		string input;
		cin>>input;
		if(input == "0"){
			bjtu.end("data.txt");
			break;
		}
		else if(input == "1"){
			string email,phone,name;
			cout<<"Input your Email: ";
			cin>>email;
			cout<<"Input your name: ";
			cin>>name;
			cout<<"Input your phonenumber: ";
			cin>>phone;
			if(!bjtu.add_person(email, name, phone)){
				cout<<"The email is existed"<<endl;
			}
			else{
				cout<<"Add successfully"<<endl;
			}
		}
		else if(input == "2"){
			string email;
			cout<<"Input the email your want to remove from database: ";
			cin>>email;
			if(bjtu.delete_person(email)){
				cout<<"The email does not exist"<<endl;
			}
			else{
				cout<<"Remove successfully"<<endl;
			}
		}
		else if(input == "3"){
			string email,group;
			cout<<"Input the gruop your want to join: ";
			cin>>group;
			cout<<"Input your email: ";
			cin>>email;
			bjtu.add_gruop(email, group);
		}
		else if(input == "4"){
			string email,group;
			cout<<"Input the gruop your want to leave: ";
			cin>>group;
			cout<<"Input your email: ";
			cin>>email;
			bjtu.delete_gruop(email, group);
		}
		else if(input == "5"){
			string email;
			cout<<"Input the email address and get the information: ";
			cin>>email;
			if(!bjtu.list_information(email)){
				cout<<"The email does not exist"<<endl;
			}
			cout<<endl<<"Input anythings to continue"<<endl;
			cin>>email;
			continue;
		}
		else{
			continue;
		}
		Sleep(1500);
	}
	return 0;
}
