// c++ 处理空行分割的方法：
	// getline(cin,s)

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
#define int long long
#define double long double
using namespace std;

struct node{
	char ch;
	int reach=0;
	vector<node*> arr;
};
node *root;

void add(string &s){
	node *index = root;
	for (int i=0; i<s.size(); i++){
		int findit = -1;
		for (int j=0; j<index->arr.size(); j++){
			if(index->arr[j]->ch == s[i]){
				findit = j;
				break;
			}
		}

		if(findit == -1){
			node *tp = new node;
			tp->ch = s[i];
			tp->reach = 1;
			index->arr.push_back(tp);
			index = tp;
		}
		else{
			index = index->arr[findit];
			index->reach++;
		}
		// cout<<index->reach<<endl;
	}
}

void ask(string &s){
	node *index=root;
	bool match = 1;
	for (int i=0;match && i<s.size(); i++){
		if(index->arr.size() == 0){
			match = 0;
		}
		for (int j=0; j<index->arr.size(); j++){
			if(index->arr[j]->ch == s[i]){
				index = index->arr[j];
				break;
			}
			if(j == index->arr.size()-1){
				match = 0;
			}
		}
	}

	if(match == 0){
		cout<<0<<endl;
		return ;
	}

	cout<<index->reach<<endl;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	string a;
	bool frontword=1;
	root = (node*)malloc(sizeof(node));
	while(getline(cin,a)){
		if(a.size() == 0){
			frontword = 0;
			continue;
		}
		if(frontword){
			add(a);
		}
		else{
			ask(a);
		}
	}
	// cout<<root->arr.size()<<endl;
	// for (int i=0; i<root->arr.size(); i++){
	//     cout<<root->arr[i]->ch<<' ';
	// }cout<<endl;

	return 0;
}
