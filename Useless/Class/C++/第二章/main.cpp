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
		string email_type;
		deque<string> message;
		node(){};
		node(string &name){
			this->name = name;
			this->email_type = "group";
		};
		node(string &name , string &phone){
			this->phone = phone;
			this->name = name;
			this->email_type = "general";
		};

	};

	sys(){};

	void begin(string file){
		ifstream fin(file);
		string address,name,phone,member,email_type;
		int num;
		while(fin>>address){
			fin>>name>>phone>>email_type>>num;
			if(email_type == "general"){
				database[address] = (node){name,phone};
			}
			else{
				database[address] = (node){name};
				for (int i=0; i<num; i++){
					fin>>member;
					database[address].lis.insert(member);
				}
			}
		}
		fin.close();
	}

	void end(string file){
		ofstream fout(file);
		for(auto i:database){
			// 输出地址
			fout<<i.first<<' ';
			auto &t = i.second;
			// 输出名字
			fout<<t.name<<' ';

			// 输出电话
			if(t.phone.empty())fout<<"----";
			else fout<<t.phone;

			// 输出类别
			fout<<' '<<t.email_type<<' ';

			// 输出子邮箱
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


	// void send(string &aim,string &message){
	// 	database[aim].message.push_back(message);
	// 	for(auto i: database[aim].lis){
	// 		send(aim,message);
	// 	}
	// }

	void find_member(string address,set<string> &has_member, set<string> &has_group){
		queue<string> que;
		que.push(address);
		while(!que.empty()){
			address = que.front();
			que.pop();
			for(string i:database[address].lis){
				if(database[i].email_type == "general"){
					has_member.insert(i);
				}
				else{
					if(has_group.count(i) == 0){
						has_group.insert(i);
						que.push(i);
					}
				}
			}
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
				set<string> has_group , has_member;
				cout<<"The general member under it: "<<endl;
				find_member(address,has_member,has_group);
				for(auto i:has_member){
					cout<<i<<endl;
				}
				cout<<"The group member under it: "<<endl;
				for(auto i:has_group){
					if(i!=address)cout<<i<<endl;
				}
			}
			return true;
		}
	}

	bool join_group(string &address , string &group){
		database[group].lis.insert(address);
	}

	bool leave_group(string &address , string &group){
		database[group].lis.erase(address);
	}

	bool add_person(string &address , string &name , string &phone){
		if(database.count(address) != 0)return false;
		database[address] = (node){name,phone};
		return true;
	}

	bool delete_person(string &address){
		if(database.count(address) != 0)return false;
		for(auto i:database){
			if(i.second.lis.count(address)!=0){
				i.second.lis.erase(address);
			}
		}
		database.erase(address);
		return true;
	}

	bool add_group(string &address , string &name ,set<string> member_list){
		if(database.count(address) != 0)return false;
		database[address] = (node){name};
		database[address].lis = member_list;
		return true;
	}

	bool delete_group(string &address){
		if(database.count(address) != 0)return false;
		for(auto i:database){
			if(i.second.lis.count(address)!=0){
				i.second.lis.erase(address);
			}
		}
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
		cout<<"[1] - create person account"<<endl;
		cout<<"[2] - remove person account"<<endl;
		cout<<"[3] - create group account"<<endl;
		cout<<"[4] - remove group account"<<endl;
		cout<<"[5] - join a group"<<endl;
		cout<<"[6] - leave a group"<<endl;
		cout<<"[7] - list one's information"<<endl;
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
			string email,name;
			set<string> lis;
			int number;
			cout<<"Input your Email: ";
			cin>>email;
			cout<<"Input your name: ";
			cin>>name;
			cout<<"Input the initial number of email address in it :";
			cin>>number;
			cout<<"Input the member's email address :";
			for (int i=0; i<number; i++){
				string one;
				cin>>one;
				lis.insert(one);
			}
			if(!bjtu.add_group(email, name, lis)){
				cout<<"The email is existed"<<endl;
			}
			else{
				cout<<"Add successfully"<<endl;
			}
		}
		else if(input == "4"){
			string email;
			cout<<"Input the group your want to remove from database: ";
			cin>>email;
			if(bjtu.delete_group(email)){
				cout<<"The email does not exist"<<endl;
			}
			else{
				cout<<"Remove successfully"<<endl;
			}
		}
		else if(input == "5"){
			string email,group;
			cout<<"Input the group your want to join: ";
			cin>>group;
			cout<<"Input your email: ";
			cin>>email;
			bjtu.join_group(email, group);
		}
		else if(input == "6"){
			string email,group;
			cout<<"Input the group your want to leave: ";
			cin>>group;
			cout<<"Input your email: ";
			cin>>email;
			bjtu.leave_group(email, group);
		}
		else if(input == "7"){
			string email;
			cout<<"Input the email address and get the information: ";
			cin>>email;
			if(!bjtu.list_information(email)){
				cout<<"The email does not exist"<<endl;
			}
			cout<<endl<<"Press anythings tocontinue"<<endl;
			// cin>>email;
			getchar();
			getchar();
			continue;
		}
		else {
			continue;
		}
		Sleep(1500);
	}
	return 0;
}
