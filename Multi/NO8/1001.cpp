#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct node{
	int mp[3][3];

	void r(int index){
		if(index == 4){
			int &t1 = mp[1][1];
			int &t2 = mp[1][2];
			int &t3 = mp[2][1];
			int &t4 = mp[2][2];
			swap(t1,t2);
			swap(t1,t3);
			swap(t3,t4);
		}
		else if(index == 3){
			int &t1 = mp[1][0];
			int &t2 = mp[1][1];
			int &t3 = mp[2][0];
			int &t4 = mp[2][1];
			swap(t1,t2);
			swap(t1,t3);
			swap(t3,t4);
		}
		else if(index == 2){
			int &t1 = mp[0][1];
			int &t2 = mp[0][2];
			int &t3 = mp[1][1];
			int &t4 = mp[1][2];
			swap(t1,t2);
			swap(t1,t3);
			swap(t3,t4);
		}
		else if(index == 1){
			int &t1 = mp[0][0];
			int &t2 = mp[0][1];
			int &t3 = mp[1][0];
			int &t4 = mp[1][1];	
			swap(t1,t2);
			swap(t1,t3);
			swap(t3,t4);
		}

	}

	void l(int index){
		if(index == 4){
			int &t1 = mp[1][1];
			int &t2 = mp[1][2];
			int &t3 = mp[2][1];
			int &t4 = mp[2][2];
			swap(t3,t4);
			swap(t1,t3);
			swap(t1,t2);
		}
		else if(index == 3){
			int &t1 = mp[1][0];
			int &t2 = mp[1][1];
			int &t3 = mp[2][0];
			int &t4 = mp[2][1];
			swap(t3,t4);
			swap(t1,t3);
			swap(t1,t2);
		}
		else if(index == 2){
			int &t1 = mp[0][1];
			int &t2 = mp[0][2];
			int &t3 = mp[1][1];
			int &t4 = mp[1][2];
			swap(t3,t4);
			swap(t1,t3);
			swap(t1,t2);
		}
		else if(index == 1){
			int &t1 = mp[0][0];
			int &t2 = mp[0][1];
			int &t3 = mp[1][0];
			int &t4 = mp[1][1];
			swap(t3,t4);
			swap(t1,t3);
			swap(t1,t2);
		}
	}
};

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		node a;
		string s;
		for (int i=0; i<3; i++){
			cin>>s;
		    for (int j=0; j<3; j++){
		        a.mp[i][j] = s[j]-'0';
		    }
		}
		for (int i=0; i<n; i++){
			cin>>s;
			if(s[1] == 'C'){
				a.r(s[0]-'0');
			}
			else{
				a.l(s[0]-'0');
			}
			// cout<<"s = "<<s<<endl;
		}
		for (int i=0; i<3; i++){
		    for (int j=0; j<3; j++){
		        cout<<a.mp[i][j];
		    }cout<<endl;
		}
	}
	return 0;
}
