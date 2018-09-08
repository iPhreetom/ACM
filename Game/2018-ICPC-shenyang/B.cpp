#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;


string s;
string now;
vector<int> lismax;
vector<int> lismin;
stack<int> smax;
stack<int> smin;
int lastmin = 1;
int lastmax = 1;

int solve(){

}

inline int toit(string &a){
	if(a.empty())return 1;
	int num = 0;
	for (int i=0; i<a.size(); i++){
		num += (a[i]-'0')*pow(10,i);
	}
	return num;
}

inline void init(){
	now.clear();
	lastmax = 1;
	lastmin = 1;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>s){
		lismin.clear();
		lismax.clear();
		reverse(s.begin(),s.end());
		if(s[s.size()-1] != '-' && s[s.size()-1] != '+')s.push_back('+');
		reverse(s.begin(),s.end());


		bool nomal = 1;
		for (int i=0; i<s.size(); i++){
			if(isdigit(s[i])){
				now.push_back(s[i]);
			}
			else{
				if(s[i] == 'd'){
					lastmax *= toit(now);
					// lastmin *= 1;
					now.clear();
				}
				else if(s[i] == ')' || s[i] == '('){
					if(s[i] == '('){
						smax.push(lastmax);
						smin.push(lastmin);
					}
					else{
						lastmin *= smin.top();
						smin.pop();
						lastmax *= smax.top();
						smax.pop();
					}
				}
				else if(s[i] == '+'){
					if(nomal){
						lismax.push_back(toit(now)*lastmax);
						lismin.push_back(toit(now)*lastmin);
					}
					else{

					}
					init();
					nomal = 1;
				}
				else if(s[i] == '-'){
					if(nomal){
						lismax.push_back(-toit(now)*lastmax);
						lismin.push_back(-toit(now)*lastmin);
					}
					else{

					}
					init();
					nomal = 0;
				}
				else if(s[i] == '*'){
					lastmax *= toit(now);
					lastmin *= toit(now);
					now.clear();
				}
			}
		}
		int maxn = 0;
		int minn = 0;
		for (int i=0; i<lismin.size(); i++){
			minn += lismin[i];
		}
		for (int i=0; i<lismax.size(); i++){
		    maxn += lismax[i];
		}
		cout<<minn<<' '<<maxn<<endl;
	}
	return 0;
}
