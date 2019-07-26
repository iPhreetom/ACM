#include<iostream>
using namespace std;

bool prime[10000];
int maxl = 10000;
int main(){
	freopen("data.txt","w",stdout);
	for(int i=0;i<maxl;i++)prime[i]=1;
	for(int i=2;i*i<maxl;i++){
		if(prime[i]){
			for(int j=i*2;j<maxl;j+=i){
				prime[j]=0;
			}
		}
	}
	for(int i=1000;i<=9999;i++){
		if(prime[i])cout<<i<<endl;
	}
}
