#ifndef E_MAIL_H
#define E_MAIL_H

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
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
	private:
		string phone;
		string name;
		set<string> lis;
		deque<string> message;

	public:
		node(){};
		node(string &phone , string &name){
			this->phone = phone;
			this->name = name;
		};
	};

	sys(){};
	void send(string &aim,string &message);
	void add_gruop(string &address , string &group);
	void sys_delete(string &address , string &group);
	void add(string &address , string &name , string &phone);
private:
	map<string,node> database;
};

#endif
