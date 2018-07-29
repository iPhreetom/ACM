#include<iostream>
#include<fstream>

using namespace std;

int main(){

	ofstream out;
	out.open("D://d.txt");
	int n = 2e5;
	out<<n<<' '<<n/100<<endl;
	for(int i=0;i<n;i++){
		out<<0<<' ';
	}

	return 0;
}
