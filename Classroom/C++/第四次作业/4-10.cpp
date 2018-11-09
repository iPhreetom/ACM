#include<bits/stdc++.h>
using namespace std;

class Date{
public:
	int year,month,day;
	Date(){}
	Date(int year, int month, int day):year(year),month(month),day(day){}
	Date(const Date &another){
		year = another.year;
		month = another.month;
		day = another.day;
	}
	~Date(){}
};


class Staff{
private:
	string employee_number;
	string id_number;
	bool gender;
	Date birth;
public:
	Staff(){}
	Staff(string employee_number,string id_number,bool gender,Date birth):
		employee_number(employee_number),
		id_number(id_number),
		gender(gender),
		birth(birth)
		{}
	Staff(const Staff &another){
		employee_number = another.employee_number;
		id_number = another.id_number;
		gender = another.gender;
		birth = another.birth;
	}
	~Staff(){}

	inline void set_employee_number(string employee_number = "00000000"){
		this->employee_number = employee_number;
	}

	inline void set_id_number(string id_number = "00000000000000"){
		this->id_number = id_number;
	}

	inline void set_gender(bool gender = 1){
		this->gender = gender;
	}

	inline void set_birth(Date birth = Date(1950,1,1)){
		this->birth = birth;
	}

	inline string get_employee_number(){
		return this->employee_number;
	}

	inline string get_id_number(){
		return this->id_number;
	}

	inline bool get_gender(){
		return this->gender;
	}

	inline Date get_birth(){
		return this->birth;
	}
};

int main(){
	return 0;
}
