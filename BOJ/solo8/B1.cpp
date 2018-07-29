#include<iostream>
using namespace std;

int n,k,a[100005],no=0,nd=0,s,d,h;

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>h;
		if(h % 2 == 1){
			no++;
		}
		else{
			ne++;
		}
	}

	h = n - k;
	if(h == 0){
		if(no % 2 == 0){
			cout<<"Daenerys"<<endl;
		}
		else{//no % 2  = 1
			cout<<"Stannis"<<endl;
		}
	}
	else{
		if(h%2 == 1){
			//s is the last one
			// d is the last second one // so d want to let out odd or if(odd%2 == 1) false else win
			d = h/2;
			s = h/2+1;

			if(h/2 > )
		}
	}
	return 0;
}
