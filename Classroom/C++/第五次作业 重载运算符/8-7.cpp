// fyt
#include<bits/stdc++.h>
using namespace std;

class counter{
public:
	int val;
	counter operator + (const counter& anthor){
		counter ret;
		ret.val = this->val + anthor.val;
		return ret;
	}
};

int main(){

	return 0;
}
