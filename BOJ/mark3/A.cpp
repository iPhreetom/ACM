#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,r;
	cin>>t>>r;
	if(t % 10 == 0){
		cout<<1<<endl;
	}
	else{
		int a,b,c;
		a =t%10;
		b =r;
		int count = 1;
		if(a == b){
			cout<<1<<endl;
		}
		else{
			while(a%10 != r && a%10 != 0){
				a += t%10;
				a%=10;
				count++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
