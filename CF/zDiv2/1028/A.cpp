// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s[150];
	for (int i=0; i<n; i++){
	    cin>>s[i];
	}

	int findit = 0;
	int x,y;
	int len = 0;
	for (int i=0; i<n && !findit; i++){
	    for (int j=0; j<m; j++){
	        if(s[i][j] == 'B'){
				for(int k=j;k<m;k++){
					if(s[i][k] == 'B'){
						len++;
					}
					else break;
				}
				x = j + len/2;
				y = i + len/2;
				findit = 1;
				break;
			}
	    }
	}
	cout<<y+1<<' '<<x+1<<endl;
	return 0;
}
