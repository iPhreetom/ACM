#include<bits/stdc++.h>
using namespace std;

void flash() {
	cout << endl;
	cout << "\t :";
	system("pause");
	system("cls");
}

void println(const string &s) {
	cout << s << endl;
}

vector<int> arrVal;

class Node {
public:
	Node *left = NULL;
	Node *right = NULL;
	int val;
	Node () {
		val = 0;
		left = NULL;
		right = NULL;
	}
	Node (int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
	bool operator < (const Node& p) const {
		return this-> val <= p.val;
	}
};

class BinaryTree {
private:
	int cnt = 0;
public:
	Node root;
	bool insert(int val) {
		Node *p = &root;
		cnt++;
		while (NULL != p) {
			if (val <= p->val) {
				if (NULL == p->left) {
					p->left = new Node(val);
					return true;
				}
				else {
					p = p->left;
				}
			}
			else { // val > p->val
				if (NULL == p->right) {
					p->right = new Node(val);
					return true;
				}
				else {
					p = p->right;
				}
			}
		}
	}
	bool reBuild() {
		cnt = 0;
		if (arrVal.empty()) return false;

		root.val = arrVal.front();
		for (int i=1; i<arrVal.size(); i++) {
			insert(arrVal[i]);
		}
	}
	bool preOrder(Node *p) {
		if (NULL != p) {
			cout << "Node : " << p->val << endl;
			if (NULL != p->left) {
				preOrder(p->left);
			}
			if (NULL != p->right) {
				preOrder(p->right);
			}
		}
		else {
			return false;
		}
	}
	bool inOrder(Node *p) {
		if (NULL != p) {
			if (NULL != p->left) {
				inOrder(p->left);
			}
			cout << "Node : " << p->val << endl;
			if (NULL != p->right) {
				inOrder(p->right);
			}
		}
		else {
			return false;
		}
	}
	bool postOrder(Node *p) {
		if (NULL != p) {
			if (NULL != p->left) {
				postOrder(p->left);
			}
			if (NULL != p->right) {
				postOrder(p->right);
			}
			cout << "Node : " << p->val << endl;
		}
		else {
			return false;
		}
	}
	bool inOrder_while() {
		stack<Node> st;
		map<Node,bool> vis;
		st.push(root);
		while (!st.empty()) {
			Node p = st.top();
			// cout << "p.val = " << p.val << endl;
			if (NULL != p.left && !vis[*p.left]) {
				st.push(*p.left);
				vis[*p.left] = true;
			}
			else {
				cout << "Node : " << p.val << endl;
				st.pop();
				if (NULL != p.right && !vis[*p.right]) {
					st.push(*p.right);
					vis[*p.right] = true;
				}
			}
		}
	}
	bool deepOrder() {
		queue<Node> que1;
		queue<Node> que2;
		bool switcher = true;
		que1.push(root);
		while (!que1.empty() || !que2.empty()) {
			cout << "[ ";
			if (switcher) {
				while (!que1.empty()) {
					Node p = que1.front();
					cout << p.val << ' ';
					if (NULL != p.left) {
						que2.push(*p.left);
					}
					if (NULL != p.right) {
						que2.push(*p.right);
					}
					que1.pop();
				}
			}
			else {
				while (!que2.empty()) {
					Node p = que2.front();
					cout << p.val << ' ';
					if (NULL != p.left) {
						que1.push(*p.left);
					}
					if (NULL != p.right) {
						que1.push(*p.right);
					}
					que2.pop();
				}
			}
			switcher = !switcher;
			cout << " ]" << endl;
		}
	}
	int getDepth() {
		queue<Node> que1;
		queue<Node> que2;
		bool switcher = true;
		que1.push(root);
		int depth = 0;
		while (!que1.empty() || !que2.empty()) {
			depth++;
			if (switcher) {
				while (!que1.empty()) {
					Node p = que1.front();
					if (NULL != p.left) {
						que2.push(*p.left);
					}
					if (NULL != p.right) {
						que2.push(*p.right);
					}
					que1.pop();
				}
			}
			else {
				while (!que2.empty()) {
					Node p = que2.front();
					if (NULL != p.left) {
						que1.push(*p.left);
					}
					if (NULL != p.right) {
						que1.push(*p.right);
					}
					que2.pop();
				}
			}
			switcher = !switcher;
		}
		return depth;
	}
	int getNumber() {
		return cnt;
	}
};


int main () {
	println("BinaryTree Homework.");
	flash();
	BinaryTree bt;
	for (int i=1; i<=10; i++) {
		arrVal.push_back(i);
	}
	random_shuffle(arrVal.begin(),arrVal.end());
	for (int i=0; i<arrVal.size(); i++) {
	    cout << arrVal[i] << ' ';
	}
	cout << endl;

	while(1) {
		println("0: rebuild");
		println("1: add node");
		println("2: show the preOrder");
		println("3: show the inOrder");
		println("4: show the inOrder while version");
		println("5: show the postOrder");
		println("6: show number of node");
		println("7: show depth of tree");
		println("8: build your own tree");
		println("*: exit");
		int k;
		cin >> k;
		switch (k) {
			case 0:
				bt.reBuild();
				break;
			case 1:
				int val;
				println("\tinput the value of the new node");
				cin >> val;
				if(bt.insert(val)){
					println("insert successful");
				}
				else {
					println("insert fail");
				}
				break;
			case 2:
				println("preOrder : ");
				bt.preOrder(&bt.root);
				break;
			case 3:
				println("inOrder : ");
				bt.inOrder(&bt.root);
				break;
			case 4:
				println("inOrder while version : ");
				bt.inOrder_while();
				break;
			case 5:
				println("postOrder : ");
				bt.postOrder(&bt.root);
				break;
			case 6:
				println("The number of node is : ");
				cout << "\t" << bt.getNumber() << endl;
				break;
			case 7:
				println("The depth of the tree is : ");
				cout << "\t" << bt.getDepth() << endl;
				break;
			case 8:
				println("input the node of the tree");
				int n;
				cin >> n;
				println("input the value of the node by inorder");
				arrVal.resize(n);
				for (int i=0; i<n; i++) {
				    cin >> arrVal[i];
				}
				break;
			default:
				return 0;
		}
		flash();
	}
	return 0;
}
// 2 1 3 4
