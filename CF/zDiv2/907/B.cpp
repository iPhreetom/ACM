// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

string a;
char mp[9][3][3];
void print(){
	for(int k = 0;k<3;k++){
		for (int i=0; i<3; i++){
			for (int j=0; j<a.size(); j++){
				cout<<mp[i][k][j];
			}
			cout<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	for(int k = 0;k<3;k++){
		for (int i=3; i<6; i++){
			for (int j=0; j<a.size(); j++){
				cout<<mp[i][k][j];
			}cout<<' ';
		}cout<<endl;
	}
	cout<<endl;
	for(int k = 0;k<3;k++){
		for (int i=6; i<9; i++){
			for (int j=0; j<a.size(); j++){
				cout<<mp[i][k][j];
			}cout<<' ';
		}cout<<endl;
	}
}

void fullpoint(){
	for(int k = 0;k<3;k++){
		for (int i=0; i<3; i++){
			for (int j=0; j<a.size(); j++){
				if(mp[i][k][j] == '.')mp[i][k][j] = '!';
			}

		}
	}
	for(int k = 0;k<3;k++){
		for (int i=3; i<6; i++){
			for (int j=0; j<a.size(); j++){
				if(mp[i][k][j] == '.')mp[i][k][j] = '!';
			}
		}
	}
	for(int k = 0;k<3;k++){
		for (int i=6; i<9; i++){
			for (int j=0; j<a.size(); j++){
				if(mp[i][k][j] == '.')mp[i][k][j] = '!';
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int k = 0;k<3;k++){
		for (int i=0; i<3; i++){
			cin>>a;
			for (int j=0; j<a.size(); j++){
				mp[i][k][j] = a[j];
			}
		}
	}
	for(int k = 0;k<3;k++){
		for (int i=3; i<6; i++){
			cin>>a;
			for (int j=0; j<a.size(); j++){
				mp[i][k][j] = a[j];
			}
		}
	}
	for(int k = 0;k<3;k++){
		for (int i=6;i<9; i++){
			cin>>a;
			for (int j=0; j<a.size(); j++){
				mp[i][k][j] = a[j];
			}
		}
	}

	int x,y;
	int px=0,py=0;
	cin>>x>>y;
	while(x > 3){
		x -= 3;
		px ++ ;
	}
	while(y > 3){
		y -= 3;
		py ++ ;
	}

	int ax=0,ay=0;
	while(x > 0){
		ax++;
		x--;
	}
	while(y > 0){
		ay++;
		y--;
	}


	int num = ax*3 + ay;
	bool full = 1;
	for (int i=0; i<3; i++){
	    for (int j=0; j<3; j++){
			if(mp[num][i][j] == '.'){
				full = 0;
			}
	    }
	}
	if(full){
		fullpoint();
	}
	else{
		for (int i=0; i<3; i++){
		    for (int j=0; j<3; j++){
		        if(mp[num][i][j] == '.')mp[num][i][j] = '!';
		    }
		}
	}
	print();

	return 0;
}
