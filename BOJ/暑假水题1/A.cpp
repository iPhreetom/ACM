#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;



int n,m;
string s;
bool ok = 0;
bool change = 1;
int len ;

void save(int index){
	for(int i=index+1;i<len;i++){
		// cout<<i<<endl;
		for(char c='a';c<m+'a';c++){
			if((i==0||c!=s[i-1]) && (i<=1||c!=s[i-2])){
				s[i] = c;
				break;
			}
		}
	}
}

int check(int index){
	for(char i=s[index]+1;i<'a'+m;i++){
		if((index==0||i!=s[index-1]) && (index==1||i!=s[index-2])){
			s[index] = i;
			return 1;
		}
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;

	len = s.size();
	for(int i=len-1;i>=0;i--){
		if(check(i)){
			save(i);
			cout<<s<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}
