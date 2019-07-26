#include<bits/stdc++.h>
#define int long long
using namespace std;




signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	string a;
	string ans;
	vector<int> num;


	while(cin>>a){
		if(a[0] == '['){
			// 转换成分数
			int rd=1,ru=0;
			int d = 1;
			int u = 0;
			int tp = 0;

			int index = 0;
			for(int i=a.size()-2;i>=0;i--){
				if(a[i] != ',' && a[i] != ';' && a[i] != '['){
					tp+=(a[i]-'0')*(pow(10,index++));
					// cout<<tp<<endl;
				}
				else{
					// cout<<tp<<endl;
					if(a[i]!='['){
						d = tp*rd + ru;
						u = rd;
						rd = d;
						ru = u;
					}
					else{
						// ;
						u += tp*d;
					}
					index = 0;
					tp = 0;
				}
			}
			cout<<u<<'/'<<d<<'\n';
		}
		else{
			num.clear();
			bool first = 1,second = 1;
			int re;
			int u=0,d=0;
			int index = 0;
			int tp=0;

			for(int i=a.size()-1;i>=0;i--){
				if(a[i] != '/'){
					tp += (a[i]-'0')*pow(10,index++);
				}
				else{
					d = tp;
					tp = 0;
					index = 0;
				}
			}
			u = tp;

			if (u != 0){
				while(u && d){
					re = u/d;
					u%=d;
					swap(u,d);
					num.push_back(re);

				}
				for(int i=-1;i<=(int)num.size();i++){
					if(i == -1){
						cout<<"[";
					}
					else if(i == num.size()){
						cout<<']'<<endl;
					}
					else if(first){
						first = 0;
						cout<<num[i];
					}
					else if(second){
						second = 0;
						cout<<';'<<num[i];
					}
					else {
						cout<<','<<num[i];
					}
				}
			}
			else{
				cout<<"[0]"<<endl;
			}
		}
	}


	return 0;
}
