#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

string f;
char c;
bool ept;
bool lie;
bool hack;
int rd = 0;
int num = 0;

multiset<char> s[4];
multiset<char> table;
multiset<char> tp;
map<int,char> mp;


void mapit(){
	for(int i=0;i<13;i++){
		if(i < 9){
			if(i == 0)mp[0] = 'A';
			else mp[i] = (i+'1');
		}
		else{
			if(i == 9)mp[i] = '1';
			if(i == 10)mp[i] = 'J';
			if(i == 11)mp[i] = 'Q';
			if(i == 12)mp[i] = 'K';
		}
	}
}

void init(){
	for (int i=0; i<4; i++){
		s[i].clear();
	}
	table.clear();
	tp.clear();
	ept = 0;
	num = 0;
	rd = 0;
}

void input(){
	if(f == "10")f = "1";
	c = f[0];
	s[0].insert(c);

	for(int i=0;i<12;i++){
		cin>>f;
		if(f == "10")f = "1";
		c = f[0];
		s[0].insert(c);
	}
	for(int i=0;i<13;i++){
		cin>>f;
		if(f == "10")f = "1";
		c = f[0];
		s[1].insert(c);
	}
	for(int i=0;i<13;i++){
		cin>>f;
		if(f == "10")f = "1";
		c = f[0];
		s[2].insert(c);
	}
	for(int i=0;i<13;i++){
		cin>>f;
		if(f == "10")f = "1";
		c = f[0];
		s[3].insert(c);
	}
}

void submit(){
	tp.clear();

	if(rd == 0){
		if(s[rd].count(mp[num]) == 0){
			lie = 1;
			char tmp = *s[rd].begin();
			tp.insert(tmp);
			table.insert(tmp);
			s[rd].erase(s[rd].find(tmp));
		}
		else{
			lie = 0;
			tp.insert(mp[num]);
			table.insert(mp[num]);
			s[rd].erase(s[rd].find(mp[num]));
		}
	}
	if(rd == 1){
		if(s[rd].count(mp[num]) == 0){
			lie = 1;
			char tmp = *s[rd].begin();
			tp.insert(tmp);
			table.insert(tmp);
			s[rd].erase(s[rd].find(tmp));
		}
		else{
			lie = 0;
			while(s[rd].count(mp[num]) != 0){
				tp.insert(mp[num]);
				table.insert(mp[num]);
				s[rd].erase(s[rd].find(mp[num]));
			}
		}
	}
	if(rd == 2){
		if(s[rd].count(mp[num]) == 0){
			lie = 1;
			int cnt = 0;
			int mncnt = 9999;
			bool first = 1;
			char ch;
			for(auto cc : s[rd]){
				if(first){
					cnt = 1;
					mncnt = 1;
					ch = cc;
					first = 0;
				}
				else{
					if(cc != ch){
						mncnt = min(mncnt,cnt);
						cnt=1;
					}
					else{
						cnt++;
					}
				}
			}
			mncnt = min(mncnt,cnt);
			
			char tpnum = *s[rd].begin();
			while(s[rd].count(tpnum) != 0){
				tp.insert(tpnum);
				table.insert(tpnum);
				s[rd].erase(s[rd].find(tpnum));
			}
		}
		else{
			lie = 0;
			while(s[rd].count(mp[num]) != 0){
				tp.insert(mp[num]);
				table.insert(mp[num]);
				s[rd].erase(s[rd].find(mp[num]));
			}
		}
	}
	if(rd == 3){
		if(s[rd].count(mp[num]) == 3 || s[rd].count(mp[num]) == 4){
			lie = 0;
			while(s[rd].count(mp[num]) != 0){
				tp.insert(mp[num]);
				table.insert(mp[num]);
				s[rd].erase(s[rd].find(mp[num]));
			}
		}
		else{
			lie = 1;
			while(s[rd].count(mp[num]) != 0){
				tp.insert(mp[num]);
				table.insert(mp[num]);
				s[rd].erase(s[rd].find(mp[num]));
			}
			if(!s[rd].empty()){
				char tmp = *s[rd].begin();
				tp.insert(tmp);
				table.insert(tmp);
				s[rd].erase(s[rd].find(tmp));
			}
			else{
				lie = 0;
			}
		}
	}
}

void hackzero(){
	if(!hack && (rd + 1)%4 == 0){ // 0
		if(s[0].count(mp[(num+1)%13]) == 0){
			//hack
			hack = 1;
			if(lie){
				for (auto k:table){
					s[rd].insert(k);
				}
				table.clear();
			}
			else{
				for (auto k:table){
					s[0].insert(k);
				}
				table.clear();
			}
		}
	}
	if(!hack && s[0].count(mp[num]) + tp.size() > 4){
		//hack
		hack = 1;
		if(lie){
			for (auto k:table){
				s[rd].insert(k);
			}
			table.clear();
		}
		else{
			for (auto k:table){
				s[0].insert(k);
			}
			table.clear();
		}
	}
}
void hackone(){
	if(!hack && (rd + 1)%4 == 1){// 1
		if(s[1].count(mp[(num+1)%13]) == 0){
			//hack
			hack = 1;
			if(lie){
				for (auto k:table){
					s[rd].insert(k);
				}
				table.clear();
			}
			else{
				for (auto k:table){
					s[1].insert(k);
				}
				table.clear();
			}
		}
	}
}
void hacktwo(){
	if(!hack){// 2
		if(s[2].count(mp[num]) == 4){
			//hack
			hack = 1;
			if(lie){
				for (auto k:table){
					s[rd].insert(k);
				}
				table.clear();
			}
			else{
				for (auto k:table){
					s[2].insert(k);
				}
				table.clear();
			}
		}
	}
}
void hackthree(){
	if(!hack){// 3
		if(s[rd].empty()){
			//hack
			hack = 1;
			if(lie){
				for (auto k:table){
					s[rd].insert(k);
				}
				table.clear();
			}
			else{
				for (auto k:table){
					s[3].insert(k);
				}
				table.clear();
			}
		}
	}
}

void hackit(){
	if(rd == 0){
		hackone();
		hacktwo();
		hackthree();
	}
	if(rd == 1){
		// hackone();
		hacktwo();
		hackthree();
		hackzero();
	}
	if(rd == 2){
		// hacktwo();
		hackthree();
		hackzero();
		hackone();
	}
	if(rd == 3){
		// hackthree();
		hackzero();
		hackone();
		hacktwo();
	}
}

void output(){
	for (int i=0; i<4; i++){
		if(s[i].size() == 0){
			cout<<"WINNER"<<endl;
		}
		else{
			bool first = 1;
			for (int j=0; j<13; j++){
			    while(s[i].count(mp[j]) != 0){
					if(mp[j] == '1'){
						if(first)cout<<"10";
						else cout<<' '<<"10";
					}
					else{
						if(first)cout<<mp[j];
						else cout<<' '<<mp[j];
					}
					s[i].erase(s[i].find(mp[j]));
					first = 0;
				}
			}
			cout<<endl;
			// for(auto cc:s[i]){
			// 	if(cc == '1'){
			// 		if(first)cout<<"10";
			// 		else cout<<' '<<"10";
			// 	}
			// 	else{
			// 		if(first)cout<<cc;
			// 		else cout<<' '<<cc;
			// 	}
			// 	first = 0;
			// }
			// cout<<endl;
		}
	}
}

void play(){
	lie = 0;
	hack = 0;

	submit();
	hackit();

	// cout<<"-----"<<endl;
	// output();
	// cout<<"-----"<<endl;
	// cout<<endl;
	num++;
	rd++;
	num%=13;
	rd%=4;
}


signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	mapit();
	while(cin>>f){
		init();
		input();
		while(!s[0].empty() && !s[1].empty() && !s[2].empty() && !s[3].empty()){
			play();
		}
		output();
	}
	return 0;
}
