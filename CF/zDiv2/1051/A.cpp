// fyt
#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int num(string &s){
	int ret = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ret++;
		}
	}
	return ret;
}

int big(string &s){
	int ret = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			ret++;
		}
	}
	return ret;
}

int small(string &s){
	int ret = 0;
	for (int i=0; i<s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			ret++;
		}
	}
	return ret;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int ttt;
	cin>>ttt;
	while(ttt--){
		string s;
		cin>>s;
		int a = num(s);
		int b = big(s);
		int c = small(s);
		if(a && b && c){

		}
		else if(!a && !b){
			s[0] = 'A';
			s[1] = '0';
		}
		else if(!a && !c){
			s[0] = 'a';
			s[1] = '0';
		}
		else if(!b && !c){
			s[0] = 'a';
			s[1] = 'A';
		}
		else if(!a){
			if(b > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= 'A' && s[i] <= 'Z'){
						s[i] = '0';
						break;
					}
				}
			}
			else if(c > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= 'a' && s[i] <= 'z'){
						s[i] = '0';
						break;
					}
				}
			}
		}
		else if(!b){
			if(a > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= '0' && s[i] <= '9'){
						s[i] = 'A';
						break;
					}
				}
			}
			else if(c > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= 'a' && s[i] <= 'z'){
						s[i] = 'A';
						break;
					}
				}
			}
		}
		else if(!c){
			if(a > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= '0' && s[i] <= '9'){
						s[i] = 'a';
						break;
					}
				}
			}
			else if(b > 1){
				for (int i=0; i<s.size(); i++){
					if(s[i] >= 'A' && s[i] <= 'Z'){
						s[i] = 'a';
						break;
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
