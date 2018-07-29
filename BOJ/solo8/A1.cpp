#include<bits/stdc++.h>
using namespace std;

int g[101];
int place[101];
bool bo[101];
int ok = -1,n,tp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	string a[101];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		cin>>g[i];
	}

	int q = 100;
	while(q--){
		for(int i=0;i<n;i++){
			if(g[i] == place[i]){
				for(int j=0;j<n;j++){
					place[j] += a[i][j]-'0';
				}
				bo[i] = 1;
				tp++;
				if(tp == n){
					ok = -1;
					break;
				}
				i = 0;
			}
			if(i == n-1){
				ok = 1;
			}
		}
	}

	if(ok == -1){
		cout<<-1<<endl;
	}
	else{
		cout<<tp<<endl;
		for(int i=0;i<n;i++){
			if(bo[i] == 1){
				cout<<i+1<<' ';
			}
		}
	}



	return 0;
}
