// 反思——以及对拍

#include<bits/stdc++.h>
using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	a.push_back(',');
	string ans1 = "\"";
	string ans2 = "\"";
	for(int i=0;i<a.size();i++){
		if(a[i] == ',' || a[i] == ';'){
			ans2.push_back(',');
		}
		else{
			if(isdigit(a[i])){
				if((a[i]-'0'==0)){
					if(isdigit(a[i+1])){
						for(int j=i;j<a.size();j++){
							if(a[j] == ',' || a[j] == ';'){
								i=j;
								ans2.push_back(',');
								break;
							}
							ans2.push_back(a[j]);
							if(j==a.size()-1)i=j;
						}
						continue;
					}
				}

				bool ok = 1;
				// string b;
				for(int j=i;j<a.size();j++){
					if(a[j] == ',' || a[j] == ';'){
						break;
					}
					if(!isdigit(a[j])){
						ok = 0;
						break;
					}
				}
				if(ok){
					for(int j=i;j<a.size();j++){
						if(a[j] == ',' || a[j] == ';'){
							i=j;
							ans1.push_back(',');
							break;
						}
						ans1.push_back(a[j]);
						if(j==a.size()-1)i=j;
					}
				}
				else{
					for(int j=i;j<a.size();j++){
						if(a[j] == ',' || a[j] == ';'){
							i=j;
							ans2.push_back(',');
							break;
						}
						ans2.push_back(a[j]);
						if(j==a.size()-1)i=j;
					}
				}
			}
			else {
				for(int j=i;j<a.size();j++){
					if(a[j] == ',' || a[j] == ';'){
						i=j;
						ans2.push_back(',');
						break;
					}
					ans2.push_back(a[j]);
					if(j==a.size()-1)i=j;
				}
			}
		}
	}





	if(ans1.size() == 1){
		cout<<"-"<<endl;
	}
	else{
		ans1[ans1.size()-1] = '\"';
		// cout<<ans1<<'\"'<<endl;
		cout<<ans1<<endl;
	}

	if(ans2.size() == 1){
		cout<<"-"<<endl;
	}
	else{
		ans2[ans2.size()-1] = '\"';
		// cout<<ans2<<'\"'<<endl;
		cout<<ans2<<endl;
	}
	return 0;
}
