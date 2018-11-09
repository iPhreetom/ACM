#include<bits/stdc++.h>
using namespace std;

class datatype{
public:
	int value_int;
	double value_double;
	char value_char;
	datatype(){}
	datatype(int value_int):value_int(value_int){}
	datatype(double value_double):value_double(value_double){}
	datatype(char value_char):value_char(value_char){}
	~datatype(){}
	void print_int(){
		cout<<value_int<<endl;
	}
	void print_double(){
		cout<<value_double<<endl;
	}
	void print_char(){
		cout<<value_char<<endl;
	}
};

int main(){
	return 0;
}
