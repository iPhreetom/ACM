#include<bits/stdc++.h>
using namespace std;

int a[550];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long b,d,s;

	cin>>b>>d>>s;

	if(d >= s && d >= b){
		if(d == s && d==b){
			cout<<0<<endl;
		}
		else{
			cout<<min(abs(d-b),abs(d-b-1)) + min(abs(d-s),abs(d-s-1))<<endl;
		}
	}
	else{

		if(b == s){
			cout<<(s-1)-d<<endl;
		}
		else{
			cout<<2*(max(b,s)-1)-min(b,s)-d<<endl;
		}
	}
	// if(b == d && b == s){
	// 	cout<<0<<endl;
	// }
	// else{
	// 	if(b > d){
	// 		if(b > s){//3 2 1
	// 			b--;
	// 			cout<<b-d + b-s<<endl;
	// 		}
	// 		else{//3 2 4 // 5 2 5
	// 			if(b == s){
	// 				b--;
	// 				s--;
	// 				cout<< s-b + s-d<<endl;
	// 			}
	// 			else{
	// 				s--;
	// 				cout<< s-b + s-d<<endl;
	// 			}
	// 		}
	// 	}
	// 	else{ // 2 5 x // 5 5 x
	// 		//less break;
	// 		if(b == d){ // 5 5 x
	// 			if(s > d){// 5 5 7
	// 				s--;
	// 				cout<<2*s-b-d;
	// 			}
	// 			else{ // 5 5 4
	// 				cout<< b - s - 1<<endl;
	// 			}
	// 		}
	// 		else{//b < d // 2 5 x
	// 			if(s == d){// 25 5
	// 				s--;
	// 				cout<<s-b<<endl;
	// 			}
	// 			else{
	// 				if(s > d){// 2 5 7
	// 					s--;
	// 					cout<<2*s - b -d <<endl;
	// 				}
	// 				else{// s < d (s?b) //   2 6 3
	// 					cout<<2*d-b-s<<endl;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	return 0;
}
