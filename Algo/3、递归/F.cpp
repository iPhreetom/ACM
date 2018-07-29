#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int y,m,d;
	cin>>y>>m>>d;

	set<int> year;
	for(int i=1949;i<=2126;i++){
		if(i%4 == 0){
			if((i%100!=0) || (i%400 == 0))
			year.insert(i);
			// cout<<i<<endl;
		}
	}
	// for(auto i:year)cout<<i<<endl;

	set<int> month;
	month.insert(1);
	month.insert(3);
	month.insert(5);
	month.insert(7);
	month.insert(8);
	month.insert(10);
	month.insert(12);


	for(int i=1;i<=10000;i++){
		d++;
		if(month.count(m)){
			if(d == 32){
				d = 1;
				m++;
				if(m == 13){
					y++;
					m = 1;
				}
			}
		}
		else{
			if(m == 2){
				if(year.count(y)){
					if(d == 30){
						d = 1;
						m++;
					}
				}
				else{
					if(d == 29){
						d = 1;
						m++;
					}
				}
			}
			else{
				if(d == 31){
					d = 1;
					m++;
				}
			}
		}
	}

	cout<<y<<'-';
	// if(m<10){
	// 	cout<<0;
	// }
	cout<<m<<'-';

	// if(d<10)cout<<0;
	cout<<d<<endl;
	return 0;
}
