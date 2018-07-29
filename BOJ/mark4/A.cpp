// CF 600A
// 	一句话描述：
// 		最后增加分割符的 字符串处理法
// 	知识点：
// 		在字符串最后，增加分隔符，简化最后一个词的处理
#include<bits/stdc++.h>
using namespace std;
int cut = 0;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	string ans1 = "\"";
	string ans2 = "\"";
	for(int i=0;i<a.size();i++){
		if(a[i] == ',' || a[i] == ';'){
			ans2.push_back(',');
			if(i!=0)cut++;
		}
		else{
			if(isdigit(a[i])){
				if((a[i]-'0'==0)){
					if(isdigit(a[i+1])){
						if((cut>0 && ans2[ans2.size()-1] != ',') ||ans2.size()!=1 && ans2[ans2.size()-1] != ',')ans2.push_back(','),cut=0;
						for(int j=i;j<a.size();j++){
							if(a[j] == ',' || a[j] == ';'){
								i=j;
								// ans2.push_back(',');
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
					if(ans1.size()!=1)ans1.push_back(',');
					for(int j=i;j<a.size();j++){
						if(a[j] == ',' || a[j] == ';'){
							i=j;
							// ans1.push_back(',');
							break;
						}
						ans1.push_back(a[j]);
						if(j==a.size()-1)i=j;
					}
				}
				else{
					if((cut>0 && ans2[ans2.size()-1] != ',') ||ans2.size()!=1 && ans2[ans2.size()-1] != ',')ans2.push_back(','),cut=0;
					for(int j=i;j<a.size();j++){
						if(a[j] == ',' || a[j] == ';'){
							i=j;
							// ans2.push_back(',');
							break;
						}
						ans2.push_back(a[j]);
						if(j==a.size()-1)i=j;
					}
				}
			}
			else {
				if((cut>0 && ans2[ans2.size()-1] != ',') ||ans2.size()!=1 && ans2[ans2.size()-1] != ',')ans2.push_back(','),cut=0;
				for(int j=i;j<a.size();j++){
					if(a[j] == ',' || a[j] == ';'){
						i=j;
						// ans2.push_back(',');
						break;
					}
					ans2.push_back(a[j]);
					if(j==a.size()-1)i=j;
				}
			}
		}
	}

	bool se=1;
	for(int i=0;i<a.size();i++){
		if(a[i] != ',' || a[i] !=';'){
			se = 0;
			break;
		}
	}
	if(a[a.size()-1]==','||a[a.size()-1]==';'){
		ans2.push_back(',');
	}



	if(ans1.size() == 1){
		cout<<"-"<<endl;
	}
	else{
		cout<<ans1<<'\"'<<endl;
	}

	if(ans2.size() == 1){
		cout<<"-"<<endl;
	}
	else{
		cout<<ans2<<'\"'<<endl;
	}
	return 0;
}
