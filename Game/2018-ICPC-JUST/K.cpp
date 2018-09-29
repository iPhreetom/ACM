// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string& trim(string &s){
    if (s.empty()){
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		while(n--){
			map<string,vector<string>> mp;
			string s;
			getline(cin,s);

			for (int qq=1; qq<=8; qq++){
				getline(cin,s);
				// if(qq != 8)
				s.pop_back();

				int eq=0;
				for (int j=0; j<s.size(); j++){
					if(s[j] == '='){
						eq = j;
						break;
					}
				}

				string tp = s.substr(0,eq);
				string val = s.substr(eq+1);

				val.pop_back();
				reverse(val.begin(),val.end());
				val.pop_back();
				reverse(val.begin(),val.end());

				if(tp != "author"){
					mp[tp].push_back(val);
				}
				else{
					vector<string> lis;
					while(!val.empty()){
						// cout<<"____"<<endl;
						int p = 0;
						for(int i=val.size()-1;i>=0;i--){
							if(val[i] == ','){
								p = i;
								break;
							}
						}

						string temp;
						if(p!=0)temp = val.substr(p+1);
						else temp = val.substr(p);
						temp = trim(temp);
						val.erase(p);

						p = 0;
						for (int i=0; i<temp.size(); i++){
							if(temp[i] == ' '){
								p = i;
								break;
							}
						}

						string st = temp.substr(p+1,1);
						temp = temp.substr(0,2)+". "+st;
						lis.push_back(trim(temp));
					}
					mp[tp] = lis;
				}

			}
			getline(cin,s);

			bool ft = 1;
			// name
			reverse(mp["author"].begin(),mp["author"].end());
			for (int i=0; i<mp["author"].size(); i++){
				if(ft){
					cout<<mp["author"][i];
					ft = 0;
				}
				else{
					cout<<", "<<mp["author"][i];
				}
			}

			//title
			cout<<". "<<mp["title"].back();

			// journal
			cout<<". "<<mp["journal"].back();

			// year volume number pages
			cout<<". "<<mp["year"].back()<<";"<<mp["volume"].back()<<"("<<mp["number"].back()<<"):"<<mp["pages"].back()<<"."<<endl;
		}
	}
	return 0;
}
