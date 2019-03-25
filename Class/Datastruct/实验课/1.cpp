#include<bits/stdc++.h>
#define MAX_LEN 55
#define MAX_LEN_S 256
using namespace std;


struct Friend {
	int number;
	int age;
	char name[MAX_LEN_S];
	char nickName[MAX_LEN_S];
};

struct FriendShipOrder {
	int len = 0;
	Friend lis[MAX_LEN];

	bool insert(int index, Friend temp) {
		if (index > len) return 0;
		else {
			if (len == MAX_LEN) return 0;
			len++;
			for (int i=len-1; i>=index+1; i--) {
				lis[i] = lis[i-1];
			}
			lis[index] = temp;
			return 1;
		}
	}

	int findit(int number) {
		for (int i=0; i<len; i++) {
			if (lis[i].number == number) {
				return i;
			}
		}
		return -1;
	}

	bool deleteit(int number) {
		for (int i=0; i<len; i++) {
			if(lis[i].number == number) {
				for (int j=i; j<len-1; j++) {
					lis[i] = lis[i+1];
				}
				len--;
				return 1;
			}
		}
		return 0;
	}

	void show() {
		for (int i=0; i<len; i++) {
			printf("%s (%s) : \n",lis[i].name,lis[i].nickName);
			printf("\tage: %d\n",lis[i].age);
			printf("\tnumber: %d\n",lis[i].number);
		}
	}
};

struct Node {
	Friend val;
	Node* next = NULL;
};

struct FriendShipLink {
	Node *head = (Node*)(malloc(sizeof(Node)));

	bool insert(Friend temp) {
		Node* point = (Node*)(malloc(sizeof(Node)));
		point->val = temp;

		if (head->next == NULL) {
			point->next = NULL;
		}
		else {
			point->next = head->next;
		}
		head->next = point;
		return 1;
	}

	bool findit(int number) {
		Node *p = head;

		if (head->next != NULL)p = p->next;
		else return 0;

		while (p->next != NULL) {
			if(p->val.number == number) {
				return 1;
			}
			p = p->next;
		}
		return 0;
	}

	bool deleteit(int number) {
		Node *p = head;

		while (p->next != NULL) {
			if(p->next->val.number == number) {
				p->next = p->next->next;
				return 1;
			}
			p = p->next;
		}
		return 0;
	}

	void show() {
		Node *p = head;

		while (p->next != NULL) {
			printf("%s (%s) : \n",p->next->val.name,p->next->val.nickName);
			printf("\tage: %d\n",p->next->val.age);
			printf("\tnumber: %d\n",p->next->val.number);
			p = p->next;
		}
	}
};

int main() {
	FriendShipOrder me;
	FriendShipLink metoo;
	metoo.head->next = NULL;

	Friend a;
	// strcpy(a.name, "12");
	// strcpy(a.nickName, "123");
	// me.insert(0,a);
	// me.insert(0,a);
	// me.show();
	// metoo.insert(a);
	// metoo.show();

	bool Order = 1;
	while(1) {
		cout << "0: swap Order/Link" << endl;
		cout << "1: insert" << endl;
		cout << "2: findit" << endl;
		cout << "3: delete" << endl;
		cout << "4: show" << endl;
		cout << "5: break" << endl;
		int t;
		cin >> t;
		if(t == 0){
			Order = !Order;
		}
		else if(t == 1){
			if(Order) {
				int index;
				Friend a;
				string name;
				string nickName;
				int number;
				int age;
				cin >> index >> number >> age >> name >> nickName;

				a.number = number;
				a.age = age;
				strcpy(a.name, name.c_str());
				strcpy(a.nickName, nickName.c_str());
				if(me.insert(index, a)){
					me.show();
				}
				else {
					cout << "Fail" << endl;
				}
			}
			else {
				int index;
				Friend a;
				string name;
				string nickName;
				int number;
				int age;
				cin >> number >> age >> name >> nickName;

				a.number = number;
				a.age = age;
				strcpy(a.name, name.c_str());
				strcpy(a.nickName, nickName.c_str());
				if(metoo.insert(a)){
					metoo.show();
				}
				else {
					cout << "Fail" << endl;
				}
			}
		}
		else if(t == 2) {
			int number;
			cin >> number;
			if(Order){
				cout << "me.findit(number) = " << me.findit(number) << endl;
			}
			else {
				cout << "metoo.findit(number) = " << metoo.findit(number) << endl;
			}
		}
		else if(t == 3) {
			int number;
			cin >> number;
			if(Order){
				if(me.deleteit(number)){
					me.show();
				}
				else {
					cout << "Fail" << endl;
				}
			}
			else {
				if(metoo.deleteit(number)){
					metoo.show();
				}
				else {
					cout << "Fail" << endl;
				}
			}
		}
		else if(t == 4) {
			if(Order){
				me.show();
			}
			else {
				metoo.show();
			}
		}
		else if(t == 5) {
			break;
		}
		cout << endl;
		cout << "________________" <<endl;
		cout << endl;
	}


	return 0;
}
