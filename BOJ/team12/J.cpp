/*
a3 >= 2
a2 >= 3

1 a3
1 a2

1 a3
2 a2




*/
#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	a[312345];
	int a2=0,a3=0,a1=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] == 1)a1++;
		if(a[i] == 2)a2++;
		if(a[i] == 3)a3++;
	}
	if(a3>=2){
		cout<<"Lose"<<endl;
	}
	else{
		if(a2>=3){
			cout<<"Lose"<<endl;
		}
		else{
			if(a3 == 0){

			}
			else{
				if(a2 >=1){
					cout<<"Lose"<<endl;
				}
				else{// 1- a3

				}
			}
		}
	}
	return 0;
}
