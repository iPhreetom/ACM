#include<bits/stdc++.h>
using namespace std;

int a,n,k,nodd=0,neven=0,h;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>k;
	h = n-k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a % 2 == 1){
			nodd++;
		}
		else{
			neven++;
		}
	}

	if(h == 0){
		if(nodd%2 == 0){
			cout<<"Daenerys"<<endl;
		}
		else{
			cout<<"Stannis"<<endl;
		}
	}
	else{
		if(h/2 >= nodd){
			cout<<"Daenerys"<<endl;
		}
		else{//nodd > h/2
			if(h%2 == 1){//操作数是基数
				int s = h/2+1;
				int d = h/2;
				//wait for
				nodd -= d;
				if(nodd % 2 == 1){
					if(s >= neven){
						s -= neven;
						nodd -= s;
					}
					else{
						;
					}
				}
				else{//nodd % 2== 0
					if(nodd == 0){
						;
					}
					else{
						nodd -= 1;
						s -= 1;
						if(s >= neven){
							s -= neven;
							nodd -= s;
						}
						else{
							;
						}
					}
				}
				if(nodd % 2 == 0){
					cout<<"Daenerys"<<endl;
				}
				else{
					cout<<"Stannis"<<endl;
				}
			}
			else{ //操作数是偶数
				int s = h/2;
				int d = h/2;
				//wait for

				if(nodd % 2 == 1){
					if(s >= neven){
						s -= neven;
						nodd -= s;
						nodd -= d;
					}
					else{
						nodd = 2;
					}
				}
				else{//nodd % 2== 0
					if(nodd == 0){
						;
					}
					else{
						if(s >= neven){
							s -= neven;
							nodd -= s;
							nodd -= d;
						}
						else{
							nodd = 2;
						}
					}
				}
				if(nodd % 2 == 0){
					cout<<"Daenerys"<<endl;
				}
				else{
					cout<<"Stannis"<<endl;
				}
			}
		}
	}
	return 0;
}
