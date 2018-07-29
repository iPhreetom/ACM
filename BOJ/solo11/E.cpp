#include<iostream>
using namespace std;

int main(){
	int n;
	int index = -1;
	int len = 0;
	string web[300];
	string cmd,url ;


	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cmd;
		if(cmd == "VISIT"){
			cin>>web[++index];
			len = index+1;
		}
		else{
			if(cmd == "BACKWARD"){
				if(index == 0 || index == -1){
					cout<<"Ignore"<<endl;
				}
				else{
					index--;
					cout<<web[index]<<endl;
				}
			}
			else{// FORWARD
				if(index+1 == len){
					cout<<"Ignore"<<endl;
				}
				else{
					index++;
					cout<<web[index]<<endl;
				}
			}
		}
	}
	return 0;
}
