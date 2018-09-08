#include "Email.h"
using namespace std;

sys::send(string &aim,string &message){
	database[aim].message.push_back(message);
	for(auto i: database[aim].lis){
		send(aim,message);
	}
}

sys::add_gruop(string &address , string &group){
	database[group].lis.insert(address);
}

sys::database_delete(string &address , string &group){
	database[group].lis.erase(address);
}

sys::add(string &address , string &name , string &phone){
	database[address] = (node){n`ame,phone};
}
