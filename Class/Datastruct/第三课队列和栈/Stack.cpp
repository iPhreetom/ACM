#include<bits/stdc++.h>
using namespace std;


#define stack_max_len 10
#define queue_max_len 5

int index = 0;

void flash() {
	cout << endl;
	cout << "\t :";
	system("pause");
	system("cls");
}

struct car{
	string id;
	int num;
	int pos;
};

struct Stack {
	car elem[stack_max_len];
	int top = 0;

	bool empty() {
		if(top == 0)return true;
		else return false;
	}

	bool full() {
		if(top == stack_max_len) return true;
		else return false;
	}

	void print(car tmp) {
		cout << "ID: " << tmp.id << endl;
		cout << "\tNumber in park: " << tmp.num << endl;
		cout << "\tPosition in park: " << tmp.pos << endl;
	}

	int find(string id) {
		for (int i=0; i<stack_max_len; i++) {
			if (elem[i].id == id) {
				return elem[i].pos;
			}
		}
		return -1;
	}

	bool push(car one) {
		if (top != stack_max_len) {
			one.pos = top+1;
			elem[top] = one;
			top ++;
			return true;
		}
		else return false;
	}

	bool pop() {
		if (top != 0) {
			top--;
			return true;
		}
		else return false;
	}

	car top_car() {
		assert (top != 0);
		return elem[top-1];
	}

	void show() {
		for (int i=0; i<top; i++) {
			print(elem[i]);
		}
	}
};

struct Queue {
	car elem[queue_max_len];
	int cnt = 0;
	int front = 0;
	int tail = 0;
	int len = 0;

	bool empty() {
		if(len == 0)return true;
		else return false;
	}

	bool full() {
		if(len == queue_max_len) return true;
		return false;
	}

	void print(car tmp) {
		cout << "ID: " << tmp.id << endl;
		cout << "\tNumber in queue: " << tmp.num << endl;
		cout << "\tPosition in queue: " << tmp.pos-cnt << endl;
	}

	int find(string id) {
		for (int i=front; i<tail; i=(i+1)%queue_max_len) {
			if(elem[i].id == id) {
				return elem[i].pos;
			}
		}
		return -1;
	}

	bool push(car one) {
		if (len != queue_max_len) {
			one.num = ++index;
			one.pos = cnt + len + 1;
			elem[tail] = one;
			tail = (tail + 1) % queue_max_len;
			len ++;
			return true;
		}
		else return false;
	}

	bool pop() {
		if (len != 0) {
			front = (front + 1) % queue_max_len;
			cnt++;
			len--;
			return true;
		}
		else return false;
	}

	car front_car() {
		assert (len != 0);
		return elem[front];
	}

	void show() {
		int count_loop = 0;
		for (int i=front; i!=tail || count_loop<len; i = (i+1)%queue_max_len) {
			count_loop++;
			print(elem[i]);
		}
	}
};

int main () {
	Stack park;
	Queue road;
	Stack out_car;

	cout << "Welcome to the BJTU_PARK!" << endl;
	cout << "Do you want to Load?[Y/N(*)]" << endl;
	cout << "\t(*) means any words except [Y] will be match" << endl;
	string s;
	cin >> s;
	if (s == "Y") {
		ifstream  fin;
		fin.open("save.txt", ios::in);
		string id;
		car tp ;
		while (fin >> id) {
			tp.id = id;
			if(!road.full()) {
				road.push(tp);
				if (!park.full()) {
					park.push(road.front_car());
					road.pop();
				}
			}
		}
		fin.close();
	}
	flash();

	while(1) {
		cout << "0: Save and end this mini park" << endl;
		cout << "1: Ceate a car enter the park" << endl;
		cout << "2: Let (id)car leave the park" << endl;
		cout << "3: Find the position of car by id" << endl;
		cout << "4: Show all information" << endl;

		int cs; cin >> cs;
		if (cs == 0) {
			ofstream fout;
			fout.open("save.txt", ios::out);
			for (int i=0; i<park.top; i++) {
				fout<<park.elem[i].id<<endl;
			}
			for (int i=road.front; i!=road.tail; i = (i+1)%queue_max_len) {
				fout<<road.elem[i].id<<endl;
			}
			break;
		}
		if (cs == 1) {
			cout << "Input the car id:" << endl;
			cout << '\t';
			string id;
			cin >> id;
			car tp;
			tp.id = id;
			if(!road.full()) {
				road.push(tp);
				if (!park.full()) {
					park.push(road.front_car());
					road.pop();
				}
				cout << "The car(" << id << ") enter the mini park." << endl;
			}
			else {
				cout << "Fail" << endl;
				cout << "The mini park is full." << endl;
			}
		}
		if (cs == 2) {
			cout << "Input the car id:" << endl;
			cout << '\t';
			string id;
			cin >> id;
			if(park.find(id) != -1) {
				while(park.top_car().id != id) {
					out_car.push(park.top_car());
					park.pop();
				}
				park.pop();
				while(!out_car.empty()) {
					park.push(out_car.top_car());
					out_car.pop();
				}
				if(!road.empty()){
					park.push(road.front_car());
					road.pop();
				}
				cout << "the car(" << id << ") is out of the park" << endl;
			}
			else {
				cout << "Can't find the id in the park." << endl;
			}
		}
		if (cs == 3) {
			cout << "Input the car id:" << endl;
			cout << '\t';
			string id;
			cin >> id;
			if(road.find(id) != -1) {
				cout << "It is in queue." << endl;
				cout << "the position is " << road.find(id) << endl;
			}
			else if(park.find(id) != -1) {
				cout << "It is in park." << endl;
				cout << "the position is " << park.find(id) << endl;
			}
			else {
				cout << "Can't find the id in this mini park." << endl;
			}
		}
		if (cs == 4) {
			cout << "In the park:" << endl;
			park.show();
			cout << "////////////////" << endl;
			cout << "In the road:" << endl;
			road.show();
		}

		flash();
	}
}

// 某单位停车场共有10个车位，是一个一端封闭的只有一排的狭长通道，
// 车辆只能由左向右依次停放，最右端有一个大门供车辆出入。
//
// 当车位未满时，车辆可以进入并停在最后一辆车的后面；
// 当车位已满时，车辆需在大门外排队等待，最多可允许5辆车排队等待。
//
// 当停车场有车辆离开时，停在后面的车要依次退出让路，
// 	待车辆驶出后再按原次序进入，
// 	之后门外等待的第一辆车可进入停车场，
// 	排队车辆依次前移一个位置。
//
// 车辆要记入的信息包括
// 	车编号、
// 	车牌号、
// 	在停车场中的位置或者排队的位置。
//
// 要求：
// 	用栈模拟停车场，
// 	用队列模拟排队等待的车辆。
//
// 实现:
// 	1 - 车辆进入停车场
// 	2 - 离开停车场、
// 	3 - 按车牌号查找车辆位置
// 	4 - 显示出停车场及等待队列中的全部车辆信息。
