#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> east,west,north,south,one,two,three,four;
pair<long long,long long> k;

void init(){
	east = make_pair((long long)pow(10,10),(long long)pow(10,10));
	west = make_pair(-(long long)pow(10,10),(long long)pow(10,10));
	north = make_pair((long long)pow(10,10),(long long)pow(10,10));
	south = make_pair((long long)pow(10,10),-(long long)pow(10,10));
	one = make_pair((long long)pow(10,10),(long long)pow(10,10));
	two = make_pair(-(long long)pow(10,10),(long long)pow(10,10));
	three = make_pair(-(long long)pow(10,10),-(long long)pow(10,10));
	four = make_pair((long long)pow(10,10),-(long long)pow(10,10));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a,b,x,y,n;
	string ch;

	bool northok = 1;
	bool southok = 1;
	bool eastok = 1;
	bool westok = 1;
	bool oneok = 1;
	bool twook = 1;
	bool threeok = 1;
	bool fourok = 1;
	bool fin = 1;

	bool ok[10];
	for(int i=0;i<10;i++){
		ok[i] = 1;
	}

	init();

	cin>>n;
	cin>>x>>y;


	for(int i=0;i<n;i++){

		cin>>ch>>a>>b;

		if(ch == "R"){
			if(x == a){
				if(b > y){
					if(north.second > b){
						north = make_pair(a,b);
						ok[1] = 0;
					}
				}
				if(b < y){
					if(south.second < b){
						south = make_pair(a,b);
						ok[2] = 0;
					}
				}
			}
			if(y == b){
				if(a > x){
					if(east.first > a){
						east = make_pair(a,b);
						ok[3] = 0;
					}
				}
				if(a < x){
					if(west.first < a){
						west = make_pair(a,b);
						ok[4] = 0;
					}
				}
			}

			if(a > x && b > y){//one
				if(abs(a-x) == abs(b-y)){
					if(one.first > a){
						one = make_pair(a,b);
						ok[5] = 1;
					}
				}
			}
			if(a < x && b > y){
				if(abs(a-x) == abs(b-y)){
					if(two.first < a){
						two = make_pair(a,b);
						ok[6] = 1;
					}
				}
			}
			if(a < x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(three.first < a){
						three = make_pair(a,b);
						ok[7] = 1;
					}
				}
			}
			if(a > x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(four.first > a){
						four = make_pair(a,b);
						ok[8] = 1;
					}
				}
			}
		}
		if(ch == "B"){
			if(a > x && b > y){//one
				if(abs(a-x) == abs(b-y)){
					if(one.first > a){
						one = make_pair(a,b);
						ok[5] = 0;
					}
				}
			}
			if(a < x && b > y){
				if(abs(a-x) == abs(b-y)){
					if(two.first < a){
						// cout<<two.first<<"-----"<<a<<endl;
						two = make_pair(a,b);
						ok[6] = 0;
					}
				}
			}
			if(a < x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(three.first < a){
						three = make_pair(a,b);
						ok[7] = 0;
					}
				}
			}
			if(a > x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(four.first > a){
						four = make_pair(a,b);
						ok[8] = 0;
					}
				}
			}

			if(x == a){
				if(b > y){
					if(north.second > b){
						north = make_pair(a,b);
						ok[1] = 1;
					}
				}
				if(b < y){
					if(south.second < b){
						south = make_pair(a,b);
						ok[2] = 1;
					}
				}
			}
			if(y == b){
				if(a > x){
					if(east.first > a){
						east = make_pair(a,b);
						ok[3] = 1;
					}
				}
				if(a < x){
					if(west.first < a){
						west = make_pair(a,b);
						ok[4] = 1;
					}
				}
			}
		}
		if(ch == "Q"){
			if(a > x && b > y){//one
				if(abs(a-x) == abs(b-y)){
					if(one.first > a){
						one = make_pair(a,b);
						ok[5] = 0;
					}
				}
			}
			if(a < x && b > y){
				if(abs(a-x) == abs(b-y)){
					if(two.first < a){
						two = make_pair(a,b);
						ok[6] = 0;
					}
				}
			}
			if(a < x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(three.first < a){
						three = make_pair(a,b);
						ok[7] = 0;
					}
				}
			}
			if(a > x && b < y){
				if(abs(a-x) == abs(b-y)){
					if(four.first > a){
						four = make_pair(a,b);
						ok[8] = 0;
					}
				}
			}

			if(x == a){
				if(b > y){
					if(north.second > b){
						north = make_pair(a,b);
						ok[1] = 0;
					}
				}
				if(b < y){
					if(south.second < b){
						south = make_pair(a,b);
						ok[2] = 0;
					}
				}
			}
			if(y == b){
				if(a > x){
					if(east.first > a){
						east = make_pair(a,b);
						ok[3] = 0;
					}
				}
				if(a < x){
					if(west.first < a){
						west = make_pair(a,b);
						ok[4] = 0;
					}
				}
			}
		}

	}

	for(int i=1;i<=8;i++){
		if(ok[i] != 1){
			// cout<<i<<endl;
			fin = 0;
		}
	}
	if(fin){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}

	return 0;
}
