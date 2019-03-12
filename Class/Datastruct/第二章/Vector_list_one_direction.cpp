// 链表实现的数组

#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next = NULL;
};
// 方法
bool insert(node *p, int index, int val) {
	// insert first element
	if (p->next == NULL) {
		if(index == 0) {
			p->next = (node*)(malloc(sizeof(node)));
			p->next->data = val;
			p->next->next = NULL;
			return 1;
		}
		else return 0;
	}
	int now = 0;
	for (; now<index-1; now++) {
		if(p->next != NULL) {
			p = p->next;
		}
		else return 0;
	}

	// make sure we reach the index-2-th element
	if(now != index-1) {
		return 0;
	}
	else {
		if(p->next == NULL) {
			p->next = (node*)(malloc(sizeof(node)));
			p->next->data = val;
			p->next->next = NULL;
		}
		else {
			node *temp = p->next;
			p->next = (node*)(malloc(sizeof(node)));
			p->next->data = val;
			p->next->next = temp;
		}
		return 1;
	}
}

void show (node *p) {
	cout << "elements: " << endl;
	cout << "[ " ;
	while (!(p->next == NULL)) {
		cout << p->next->data << ' ';
		p = p->next;
	}
	cout << ']' << endl;
}



int main() {

	node lis;
	insert(&lis, 0, 0);
	for (int i=1; i<=10; i++) {
		insert(&lis,1,i);
	}
	show(&lis);
	return 0;
}
