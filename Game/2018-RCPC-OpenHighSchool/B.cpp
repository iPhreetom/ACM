// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;
unordered_map<string,string> mp;

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string begin = "\\begin{thebibliography}{99}";
	string ended = "\\end{thebibliography}";
	vector<string> order;
	vector<string> now;

	bool start = 0;
	int index = 0;
	bool first = 1;
	bool ok = 1;
	while(1){
		string tp;
		if(start){
			// getline
			if(first)getline(cin,tp),first = 0;
			getline(cin,tp);
			if(tp == ended){
				break;
			}
			else{
				// 它输入的顺序
				int end_index = 0;
				for (int i=0; i<tp.size(); i++){
					if(tp[i] == '}'){
						end_index = i;
						break;
					}
				}
				string name = tp.substr(8,end_index-8+1);
				if(name != order[index]){
					ok = 0;
				}

				index++;
				mp[name] = tp;
			}
		}
		else{
			cin >> tp;
			if(tp == begin){
				start = 1;
			}
			else{
				// 真实的顺序
				if(tp[0] == '\\'){
					order.push_back(tp.substr(5));
					while(order.back().back() != '}')order.back().pop_back();
				}
			}
		}
	}
	if(ok){
		cout<<"Correct"<<endl;
	}
	else{
		cout<<"Incorrect"<<endl;
		cout<<begin<<endl;
		for (int i=0; i<order.size(); i++){
			cout<<mp[order[i]]<<endl;
		}
		cout<<ended<<endl;
	}
	return 0;
}
