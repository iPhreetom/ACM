//策略
#include<bits/stdc++.h>
using namespace std;


/*
2 2 2
3 3 3
5 5 5
=
4 6 3 -- 1 3 0
5 7 4 -- 1 3 0
7 9 6 -- 1 3 0

*/

int m[105][105];
int cow,col;
int ncow[105],ncol[105];
int nzw=0,nzl=0;
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cow>>col;
	for(int i=1;i<=cow;i++){
		for(int j=1;j<=col;j++){
			cin>>m[i][j];
			if(m[i][j] != 0){
				ncow[i]=1;
				ncol[j]=1;
			}
		}
	}

	for(int i=1;i<105;i++){
		if(ncow[i]==1)nzw++;
		if(ncol[i]==1)nzl++;
	}

	if(nzw <= nzl){
		for(int i=1;i<=cow;i++){
			int mn=100000;
			for(int j=1;j<=col;j++){
				mn = min(mn,m[i][j]);
			}
			if(mn != 0){
				for(int j=1;j<=col;j++){
					m[i][j] -= mn;
				}
				while(mn--){
					ans.push_back(0);
					ans.push_back(i);
				}
				// 0 - row                 1 - col
				//row
				//for
			}
		}

		for(int i=1;i<=col;i++){
			int mn=100000;
			for(int j=1;j<=cow;j++){
				mn = min(mn,m[j][i]);
			}
			if(mn != 0){
				for(int j=1;j<=cow;j++){
					m[j][i] -= mn;
				}
				while(mn--){
					ans.push_back(1);
					ans.push_back(i);
				}
			}
		}
	}
	else{
		for(int i=1;i<=col;i++){
			int mn=100000;
			for(int j=1;j<=cow;j++){
				mn = min(mn,m[j][i]);
			}
			if(mn != 0){
				for(int j=1;j<=cow;j++){
					m[j][i] -= mn;
				}
				while(mn--){
					ans.push_back(1);
					ans.push_back(i);
				}
				// 0 - row                 1 - col
				//row
				//for
			}
		}

		for(int i=1;i<=cow;i++){
			int mn=100000;
			for(int j=1;j<=col;j++){
				mn = min(mn,m[i][j]);
			}
			if(mn != 0){
				for(int j=1;j<=cow;j++){
					m[i][j] -= mn;
				}
				while(mn--){
					ans.push_back(0);
					ans.push_back(i);
				}
			}
		}
	}
	for(int i=1;i<=cow;i++){
		for(int j=1;j<=col;j++){
			if(m[i][j] != 0){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<ans.size()/2<<endl;
	for(int i=0;i<ans.size();i+=2){
		if(ans[i]==0){
			cout<<"row "<<ans[i+1]<<endl;
		}
		else{
			cout<<"col "<<ans[i+1]<<endl;
		}
	}

	return 0;
}
