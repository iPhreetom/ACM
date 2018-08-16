#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int maxn = 20000;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string ss(20000,'0');
		int m;
		bool findb=0;
		bool findc=0;
		bool ips=0;

		cin>>m;
		for (int i=0; i<m; i++){
			int p;
			char c;
			cin>>p>>c;
			ss[p-1]=c;
		}

		// special judge 'NO'
		bool no = 0;
		if(ss[0] != 'A' && ss[0] != '0')no = 1;
		if(ss[1] == 'C')no = 1;
		for (int i=0; i<maxn-1; i++){
			if(ss[i] == 'B' && ss[i+1] == 'A')no = 1;
			else if(ss[i] == 'C' && ss[i+1] == 'B')no = 1;
			else if(ss[i] == 'A' && ss[i+1] == 'C')no = 1;
			if(no){
				cout<<"NO"<<endl;
			}
		}



	}
	return 0;
}
