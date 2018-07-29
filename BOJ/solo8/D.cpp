#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	register long long m,a1,a2,x1,x2,y1,y2,h1,h2;
	register long long t = 0;

	cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
	register long long mx = m+100;
	register long long a= -1,b= -1,at=0,bt=0;
	register bool ab=1;
	// a is the first varible's cycle when it can reach the a1
	// b is the second varible's cycle when it can reach the b1

	for(t = 0;t<=mx;t++){
		if(h1 == a1){
			a = t;
			for(int i=1;i<=mx;i++){
				h1 = x1*h1+y1;
				h1 %= m;
				if(h1 == a1){
					at = i;
					break;
				}
			}
			break;
		}
		else{
			h1 = x1*h1+y1;
			// h2 = x2*h2+y2;
			h1 %= m;
			// h2 %= m;
		}
	}

	for(t = 0;t<=mx;t++){
		if(h2 == a2){
			b = t;
			for(int i=1;i<=mx;i++){
				h2 = x2*h2+y2;
				h2 %= m;
				if(h2 == a2){
					bt = i;
					break;
				}
			}
			break;
		}
		else{
			h2 = x2*h2+y2;
			// h2 = x2*h2+y2;
			h2 %= m;
			// h2 %= m;
		}
	}

	if(a == -1 || b == -1 || at == 0 || bt == 0){
		cout<<-1<<endl;
	}
	else{
		//怎么算两个的共同周期？
		// a + k*at == b + m*bt
		// solve k and m
		// a - b = m*bt - k*at
		if(a == b){
			cout<<a<<endl;
		}
		else{
			ab = a>b?1:0;
			for(register int i = 0;i<=12345678;i++){
				if(i == 12345678){
					cout<<-1<<endl;
					break;
				}
				if(a == b){
					cout<<a<<endl;
					break;
				}
				if(ab){
					b += bt;
				}
				else{
					a += at;
				}
			}
		}

	}
	return 0;
}
