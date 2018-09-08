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
		node(string &phone , string &name){
			this->phone = phone;
			this->name = name;
		};
	};

	sys(){};

	void begin(string file){
		ifstream fin;
		string address,name,phone,group;
		while()
	}

	void send(string &aim,string &message){
		database[aim].message.push_back(message);
		for(auto i: database[aim].lis){
			send(aim,message);
		}
	}

	void add_gruop(string &address , string &group){
		database[group].lis.insert(address);
	}

	void delete_gruop(string &address , string &group){
		database[group].lis.erase(address);
	}

	void delete_person(string &address){
		database.erase(address);
	}

	void add_person(string &address , string &name , string &phone){
		database[address] = (node){name,phone};
	}

private:
	map<string,node> database;
};




int main(){
	sys bjtu;
	sys.begin("data.txt");


	ofstream fout;
	return 0;
}
