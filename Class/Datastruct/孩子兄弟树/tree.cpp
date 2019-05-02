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


class Node {
public:
	Node *left;
	Node *right;
	char ch;
	Node() {
		left = NULL;
		right = NULL;
	}
	Node(char ch) {
		this->ch = ch;
		left = NULL;
		right = NULL;
	}
};

class Tree {
private:
	Node *root;
	int BinaryTree_depth;
	int NormalTree_depth;
	set<char> fa;
	set<char> ch;
public:
	Tree() {
		root = new Node('#');
		BinaryTree_depth = 0;
		NormalTree_depth = 0;
		fa.clear();
		ch.clear();
		fa.insert('#');
	}
	void dfs(Node *p, char father, char child, int dp, int dp2) {
		BinaryTree_depth = max(dp,BinaryTree_depth);
		if (p->ch == father) {
			if (NULL == p->left) {
				p->left = new Node(child);
				ch.insert(child);
				fa.insert(child);
				NormalTree_depth = max(NormalTree_depth, dp2+1);
				BinaryTree_depth = max(BinaryTree_depth, dp+1);
				return ;
			}
			else {
				Node *v = p->left;
				dp++;
				while(NULL != v->right) {
					v = v->right;
					dp++;
				}
				dp++;
				BinaryTree_depth = max(dp,BinaryTree_depth);
				v->right = new Node(child);
				ch.insert(child);
				fa.insert(child);
				return ;
			}
		}
		else {
			if (NULL != p->left) {
				dfs(p->left, father, child, dp+1, dp2+1);
			}
			if (NULL != p->right) {
				dfs(p->right, father, child, dp+1, dp2);
			}
		}
	}
	bool push(string s) {
		if (fa.count(s.front()) == 0) {
			println("Father doesn't exist.");
			return false;
		}
		if (ch.count(s.back()) != 0) {
			println("This child has father");
			return false;
		}
		dfs(root, s.front(), s.back(), 0, 0);
		return true;
	}
	bool init_with_edge(string s) {
		if (s.front() != '#')return false;
		if (s.back() == '#')return false;
		if (s.front() == s.back())return false;
		return push(s);
	}
	bool init_with_degree(string s1, string s2) {
		vector<string> mp;
		int index = 0;
		int cnt = s2[index]-'0';
		int now = 0;
		mp.push_back("#");
		mp.back() += s1[0];

		for (int i=1; i<s1.size(); i++){
			if (now < cnt) {
				mp.push_back("");
				mp.back() += s1[index];
				mp.back() += s1[i];
				now++;
			}
			else {
				index++;
				i--;
				cnt = s2[index]-'0';
				now = 0;
			}
		}

		for (int i=0; i<mp.size(); i++){
		    cout<<mp[i]<<' ';
		}cout<<endl;
		init_with_edge(mp[0]);
		for (int i=1; i<mp.size(); i++){
			push(mp[i]);
		}
	}
	void clear() {
		root = new Node('#');
		BinaryTree_depth = 0;
		NormalTree_depth = 0;
		fa.clear();
		ch.clear();
		fa.insert('#');
	}
	void output() {
		println("The depth of the BinaryTree.");
		cout << "\t" << BinaryTree_depth << endl;
		println("The depth of the NormalTree.");
		cout << "\t" << NormalTree_depth << endl;
	}
};

void tip_edge() {
	println("#####################################");
	println("                tip:                 ");
	println("Please input the tree line by line");
	println("Each line contain two characters. ");
	println("    First character is the father node. ");
	println("    Second character is the son node. ");
	println("First line begin with #_ ");
	println("Last line end with ## ");
	println("Example:");
	println("   #A");
	println("   AB");
	println("   ##");
	println("#####################################");
	flash();
}

void tip_degree() {
	println("#####################################");
	println("                tip:                 ");
	println("Please input the tree with two line");
	println("First line is the name of each Node");
	println("Second line is the degree of each Node");
	println("Example:");
	println("   ABC");
	println("   200");
	println("#####################################");
	flash();
}

int main () {
	Tree tree;
	while (1) {
		println("Select input type:");
		println("    1 : input the edge");
		println("    2 : input the degree");
		int num ;
		cin >> num ;
		if (num == 1) {
			tree.clear();
			tip_edge();
			string s;
			while (1) {
				cin >> s;
				if(s.size() != 2) {
					println("Wrong! You don't follow the tip.");
					println("Please try again.");
					continue;
				}

				if (s.front() == '#') {
					if (s.back() == '#') {
						break;
					}
					else {
						if(tree.init_with_edge(s)){
							println("\t Accept.");
						}
						else {
							println("Wrong! You don't follow the tip.");
							println("Please try again.");
							continue;
						}
					}
				}
				else {
					if(tree.push(s)){
						println("\t Accept.");
					}
					else {
						println("Wrong! You don't follow the tip.");
						println("Please try again.");
						continue;
					}
				}
			}
			tree.output();
		}
		else if (num == 2) {
			tree.clear();
			tip_degree();
			string s1, s2;
			while (1) {
				cin >> s1 >> s2;
				if (s1.size() != s2.size()) {
					println("The length of two line is different");
					continue;
				}
				if (tree.init_with_degree(s1,s2))  {
					tree.output();
					break;
				}
				else {
					println("Please check your input, and input again.");
				}
			}
		}
		else {
			println("Wrong. Please input again.");
		}
		flash();
	}
}
