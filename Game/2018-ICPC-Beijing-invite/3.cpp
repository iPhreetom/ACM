#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map<int,char> mp;
multiset<char> s[4];
string f;
char c ;


void init(){
	for(int i=0;i<13;i++){
		if(i < 9){
			if(i == 0)mp[1] = 'A';
			else mp[i] = (i+'1');
		}
		else{
			if(i == 9)mp[i] = '1';
			if(i == 10)mp[i] = 'J';
			if(i == 11)mp[i] = 'Q';
			if(i == 12)mp[i] = 'K';
		}
	}
	for (int i=0; i<4; i++){
		s[i].clear();
	}
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

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	while(cin>>f){
		multiset<char> table;
		init();
		input();

		int rd = 0;
		int num = 0;
		while(!s[0].empty() && !s[1].empty() && !s[2].empty() && !s[3].empty()){

			if(rd == 0){
				bool lie;
				set<char> tp;
				// 处理他出牌
				if(s[rd].count(mp[num]) == 0){
					lie = 1;
					tp.insert(*s[rd].begin());
					table.insert(*s[rd].begin());
					s[rd].erase(*s[rd].begin());
				}
				else{
 					lie = 0;
					tp.insert(mp[num]);
					table.insert(mp[num]);
					s[rd].erase(mp[num]);
				}


				bool hack = 0;
				// 处理别人的hack
				int next;
				if(!hack){// 1
					if(s[(rd+1)%4].count(mp[(num+1)%13]) == 0){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
				if(!hack){// 2
					if(s[(rd+1)%4].count(mp[num]) == 4){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}


			}
			// 0

			if(rd == 1){
				bool lie;
				multiset<char> tp;
				// 处理他出牌
				if(s[rd].count(mp[num]) == 0){
					lie = 1;
					tp.insert(*s[rd].begin());
					table.insert(*s[rd].begin());
					s[rd].erase(*s[rd].begin());
				}
				else{
 					lie = 0;
					while(s[rd].count(mp[num]) != 0){
						tp.insert(mp[num]);
						table.insert(mp[num]);
						s[rd].erase(s[rd].find(mp[num]));
					}
				}


				bool hack = 0;
				// 处理别人的hack
				int next;
				if(!hack){// 2
					if(s[(rd+1)%4].count(mp[num]) == 4){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
				if(!hack){ // 0
					if(s[(rd+1)%4].count(mp[(num+1)%13]) == 0){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
					if(s[(rd+1)%4].count(num) + tp.size() > 4){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
			}
			// 1

			if(rd == 2){
				bool lie;
				multiset<char> tp;
				// 处理他出牌
				if(s[rd].count(mp[num]) == 0){
					lie = 1;
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


				bool hack = 0;
				// 处理别人的hack
				int next;
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
				if(!hack){ // 0
					if(s[(rd+1)%4].count(mp[(num+1)%13]) == 0){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
					if(s[(rd+1)%4].count(num) + tp.size() > 4){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
				if(!hack){// 1
					if(s[(rd+1)%4].count(mp[(num+1)%13]) == 0){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
			}
			// 2

			if(rd == 3){
				bool lie;
				multiset<char> tp;
				// 处理他出牌
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
						*s[rd].begin();
						tp.insert(*s[rd].begin());
						table.insert(*s[rd].begin());
						s[rd].erase(s[rd].find(*s[rd].begin()));
					}
				}


				bool hack = 0;
				// 处理别人的hack
				int next;
				wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwaz				if(!hack){// 1
					if(s[(rd+1)%4].count(mp[(num+1)%13]) == 0){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
				if(!hack){// 2
					if(s[(rd+1)%4].count(mp[num]) == 4){
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
								s[(rd+1)%4].insert(k);
							}
							table.clear();
						}
					}
				}
			}
			// 3
			//end
			num++;
			num%=13;
			rd++;
			rd%=4;
		}
		for (int i=0; i<4; i++){
		    if(s[i].size() == 0){
				cout<<"WINNER"<<endl;
			}
			else{
				bool first = 1;
				for(auto cc:s[i]){
					if(first)cout<<cc;
					else cout<<' '<<cc;
					first = 0;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
