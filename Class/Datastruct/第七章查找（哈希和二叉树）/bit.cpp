#include<bits/stdc++.h>
using namespace std;

void flash() {
	cout << endl;
	cout << "\t :";
	system("pause");
	system("cls");
}

struct Node {
	string s;
	Node *lt = NULL;
	Node *rt = NULL;
	Node () {
		lt = NULL;
		rt = NULL;
	}
	Node (string s) {
		this->s = s;
		lt = NULL;
		rt = NULL;
	}
};

struct Tree {
	int sum = 0;
	Node *root = NULL;
	Tree(){
		root = NULL;
	}
	void insert(string s){
		Node *p = root;
		int cnt = 0;
		if (root == NULL) {
			root = new Node(s);
		}
		else {
			while (true) {
				if (s <= p->s) {
					if (s == p->s) {
						cout << "Exist" << endl;
						return ;
					}
					if (p->lt == NULL) {
						p->lt = new Node(s);
						sum += cnt;
						return ;
					}
					else {
						p = p->lt;
						cnt++;
					}
				}
				else {
					if (p->rt == NULL) {
						p->rt = new Node(s);
					}
						else {
						cnt++;
						p = p->rt;
					}
				}
			}
		}
		report();
	}
	bool find(string s) {
		if (root == NULL) {
			insert(s);
			report();
			return false;
		}
		else {
			Node *p = root;
			while (true) {
				if (s == p->s) {
					report();
					return true;
				}
				if (s <= p->s) {
					if (p->lt == NULL) {
						insert(s);
						report();
						return false;
					}
					p = p->lt;
				}
				else {
					if (p->rt == NULL) {
						insert(s);
						report();
						return false;
					}
					p = p->rt;
				}
			}
		}
	}
	void dfs(Node *p) {
		if (p == NULL) {
			return ;
		}
		else {
			if (p->lt != NULL) {
				dfs(p->lt);
			}
			else {
				cout << p->s << endl;
				if (p->rt != NULL) {
					dfs(p->rt);
				}
			}
		}
	}
	void report () {
		Node *p = root;
		if (root == NULL) {
			cout << "Empty" << endl;
			return ;
		}
		else {
			dfs(root);
		}
	}
};


int main () {
	Tree tree;
	while(1){
		// cout << "1: insert" << endl;
		// cout << "2: find" << endl;
		// int tp;
		// cin >> tp;
		cout << "Input the value:" << endl;
		int tp = 2;
		if (tp == 1) {
			string s;
			cin >> s;
			tree.insert(s);
		}
		if (tp == 2) {
			string s;
			cin >> s;
			cout << endl;
			cout << "tree:" << endl;
			if (tree.find(s) ) {
				cout << endl;
				cout << "Find it" << endl;
			}
			else {
				cout << endl;
				cout << "Not find" << endl;
			}
		}
		flash();
	}
	return 0;
}
// 2 1 3 4
